using System;
using Plunt.Interpreter.Bindings;

namespace Plunt.Interpreter
{
    public class Program
    {
        public static void Main(string[] args)
        {
            string inputCode = GetInputCode(args);

            if (string.IsNullOrWhiteSpace(inputCode))
            {
                Console.WriteLine("Usage: BotkaInterpreter [code] or pipe code via stdin");
                return;
            }

            Console.WriteLine($"=== Input ===\n{inputCode.Trim()}\n");

            try
            {
                using var binding = new TreeSitterBinding();
                var tree = binding.Parse(inputCode);

                Console.WriteLine("=== Tokens ===");
                PrintTokens(tree.RootNode);

                if (tree.HasErrors)
                {
                    Console.WriteLine($"\n[WARN] Parse errors: {tree.GetError()}");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[ERROR] {ex.Message}");
            }
        }

        private static string GetInputCode(string[] args)
        {
            if (args.Length > 0)
                return string.Join(" ", args);

            if (Console.IsInputRedirected)
                return Console.In.ReadToEnd();

            return "forward 5;";
        }

        private static void PrintTokens(TreeSitterNode node, int depth = 0)
        {
            var indent = new string(' ', depth * 2);
            var text = node.Text.Replace("\n", "\\n").Replace("\r", "\\r").Trim();

            if (!string.IsNullOrEmpty(text))
                Console.WriteLine($"{indent}{node.Type}: \"{text}\"");

            foreach (var child in node.Children)
                PrintTokens(child, depth + 1);
        }
    }
}
