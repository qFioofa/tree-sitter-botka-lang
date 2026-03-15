using System;
using System.IO;
using System.Runtime.InteropServices;

namespace Plunt.Interpreter.Bindings
{
    public class TreeSitterBinding : IDisposable
    {
        private IntPtr _parser;
        private IntPtr _language;
        private bool _disposed;
        private static IntPtr _libraryHandle;

        // Tree-sitter function delegates (internal for nested classes)
        internal readonly GetLanguageDelegate _getLanguage;
        internal readonly ts_parser_new_delegate _ts_parser_new;
        internal readonly ts_parser_set_language_delegate _ts_parser_set_language;
        internal readonly ts_parser_parse_string_delegate _ts_parser_parse_string;
        internal readonly ts_tree_root_node_delegate _ts_tree_root_node;
        internal readonly ts_tree_delete_delegate _ts_tree_delete;
        internal readonly ts_parser_delete_delegate _ts_parser_delete;
        internal readonly ts_node_type_delegate _ts_node_type;
        internal readonly ts_node_start_byte_delegate _ts_node_start_byte;
        internal readonly ts_node_end_byte_delegate _ts_node_end_byte;
        internal readonly ts_node_start_point_delegate _ts_node_start_point;
        internal readonly ts_node_child_count_delegate _ts_node_child_count;
        internal readonly ts_node_child_delegate _ts_node_child;
        internal readonly ts_node_is_error_delegate _ts_node_is_error;

        public bool IsReady => _parser != IntPtr.Zero && _language != IntPtr.Zero;

        public TreeSitterBinding()
        {
            if (_libraryHandle == IntPtr.Zero)
            {
                _libraryHandle = LoadLibrary();
            }

            _getLanguage = GetExport<GetLanguageDelegate>("tree_sitter_botka");
            _ts_parser_new = GetExport<ts_parser_new_delegate>("ts_parser_new");
            _ts_parser_set_language = GetExport<ts_parser_set_language_delegate>("ts_parser_set_language");
            _ts_parser_parse_string = GetExport<ts_parser_parse_string_delegate>("ts_parser_parse_string");
            _ts_tree_root_node = GetExport<ts_tree_root_node_delegate>("ts_tree_root_node");
            _ts_tree_delete = GetExport<ts_tree_delete_delegate>("ts_tree_delete");
            _ts_parser_delete = GetExport<ts_parser_delete_delegate>("ts_parser_delete");
            _ts_node_type = GetExport<ts_node_type_delegate>("ts_node_type");
            _ts_node_start_byte = GetExport<ts_node_start_byte_delegate>("ts_node_start_byte");
            _ts_node_end_byte = GetExport<ts_node_end_byte_delegate>("ts_node_end_byte");
            _ts_node_start_point = GetExport<ts_node_start_point_delegate>("ts_node_start_point");
            _ts_node_child_count = GetExport<ts_node_child_count_delegate>("ts_node_child_count");
            _ts_node_child = GetExport<ts_node_child_delegate>("ts_node_child");
            _ts_node_is_error = GetExport<ts_node_is_error_delegate>("ts_node_is_error");

            _language = _getLanguage();
            _parser = _ts_parser_new();
            _ts_parser_set_language(_parser, _language);
        }

        private static IntPtr LoadLibrary()
        {
            var libName = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
                ? "tree-sitter-plunt.dll"
                : RuntimeInformation.IsOSPlatform(OSPlatform.OSX)
                    ? "libtree-sitter-plunt.dylib"
                    : "libtree-sitter-plunt.so";

            var basePath = AppContext.BaseDirectory;
            var libPath = Path.Combine(basePath, "bin", libName);

            if (!File.Exists(libPath))
                libPath = Path.Combine(basePath, libName);

            if (File.Exists(libPath))
            {
                return NativeLibrary.Load(libPath);
            }

            throw new FileNotFoundException($"Native library not found: {libPath}");
        }

        private T GetExport<T>(string name)
        {
            var addr = NativeLibrary.GetExport(_libraryHandle, name);
            return Marshal.GetDelegateForFunctionPointer<T>(addr);
        }

        public TreeSitterTree Parse(string sourceCode)
        {
            ObjectDisposedException.ThrowIf(_disposed, this);
            ArgumentException.ThrowIfNullOrEmpty(sourceCode);

            var treePtr = _ts_parser_parse_string(_parser, IntPtr.Zero, sourceCode, (uint)sourceCode.Length);

            return treePtr != IntPtr.Zero
                ? new TreeSitterTree(treePtr, sourceCode, this)
                : throw new InvalidOperationException("Failed to parse source code");
        }

        public void Dispose()
        {
            if (!_disposed)
            {
                if (_parser != IntPtr.Zero)
                {
                    _ts_parser_delete(_parser);
                    _parser = IntPtr.Zero;
                }
                _disposed = true;
            }
        }

        // Delegates for tree-sitter functions (internal for nested classes)
        internal delegate IntPtr GetLanguageDelegate();
        internal delegate IntPtr ts_parser_new_delegate();
        internal delegate void ts_parser_set_language_delegate(IntPtr parser, IntPtr language);
        internal delegate IntPtr ts_parser_parse_string_delegate(IntPtr parser, IntPtr oldTree, string source, uint length);
        internal delegate TSNode ts_tree_root_node_delegate(IntPtr tree);
        internal delegate void ts_tree_delete_delegate(IntPtr tree);
        internal delegate void ts_parser_delete_delegate(IntPtr parser);
        internal delegate IntPtr ts_node_type_delegate(TSNode node);
        internal delegate uint ts_node_start_byte_delegate(TSNode node);
        internal delegate uint ts_node_end_byte_delegate(TSNode node);
        internal delegate TSPoint ts_node_start_point_delegate(TSNode node);
        internal delegate uint ts_node_child_count_delegate(TSNode node);
        internal delegate TSNode ts_node_child_delegate(TSNode node, uint index);
        internal delegate bool ts_node_is_error_delegate(TSNode node);
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct TSNode
    {
        public uint Context1;
        public uint Context2;
        public uint Context3;
        public uint Context4;
        public IntPtr Id;
        public IntPtr Tree;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct TSPoint
    {
        public uint Row;
        public uint Column;
    }

    public class TreeSitterTree : IDisposable
    {
        private readonly IntPtr _treePtr;
        private readonly string _sourceCode;
        private readonly TreeSitterBinding _binding;
        private bool _disposed;

        public TreeSitterTree(IntPtr treePtr, string sourceCode, TreeSitterBinding binding)
        {
            _treePtr = treePtr;
            _sourceCode = sourceCode;
            _binding = binding;
        }

        public TreeSitterNode RootNode
        {
            get
            {
                var tsNode = _binding._ts_tree_root_node(_treePtr);
                return new TreeSitterNode(
                    tsNode,
                    _sourceCode,
                    (int)_binding._ts_node_start_byte(tsNode),
                    (int)_binding._ts_node_end_byte(tsNode),
                    _binding
                );
            }
        }

        public bool HasErrors => CheckForErrors(RootNode);
        public string? GetError() => HasErrors ? "Syntax errors detected" : null;

        private static bool CheckForErrors(TreeSitterNode node)
        {
            if (node.IsError) return true;
            foreach (var child in node.Children)
                if (CheckForErrors(child)) return true;
            return false;
        }

        public void Dispose()
        {
            if (!_disposed && _treePtr != IntPtr.Zero)
            {
                _binding._ts_tree_delete(_treePtr);
                _disposed = true;
            }
        }
    }

    public class TreeSitterNode
    {
        private readonly TSNode _tsNode;
        private readonly string _sourceCode;
        private readonly int _startByte;
        private readonly int _endByte;
        private readonly TreeSitterBinding _binding;

        public TreeSitterNode(TSNode tsNode, string sourceCode, int startByte, int endByte, TreeSitterBinding binding)
        {
            _tsNode = tsNode;
            _sourceCode = sourceCode;
            _startByte = startByte;
            _endByte = endByte;
            _binding = binding;
        }

        public string Type => Marshal.PtrToStringAnsi(_binding._ts_node_type(_tsNode)) ?? "unknown";
        public string Text => _sourceCode.Substring(_startByte, _endByte - _startByte);
        public int StartLine => (int)_binding._ts_node_start_point(_tsNode).Row;
        public bool IsError => _binding._ts_node_is_error(_tsNode);
        public int ChildCount => (int)_binding._ts_node_child_count(_tsNode);

        public IEnumerable<TreeSitterNode> Children
        {
            get
            {
                for (uint i = 0; i < ChildCount; i++)
                {
                    var child = _binding._ts_node_child(_tsNode, i);
                    var start = (int)_binding._ts_node_start_byte(child);
                    var end = (int)_binding._ts_node_end_byte(child);
                    yield return new TreeSitterNode(child, _sourceCode, start, end, _binding);
                }
            }
        }
    }
}
