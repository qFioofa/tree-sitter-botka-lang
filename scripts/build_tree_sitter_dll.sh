#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
SRC_DIR="$PROJECT_ROOT/src"
OUTPUT_DIR="$PROJECT_ROOT/interpreter/bin"
TS_RUNTIME="/usr/local/lib/node_modules/tree-sitter/vendor/tree-sitter/lib"

if [ "$1" = "clean" ]; then
    rm -f "$OUTPUT_DIR"/tree-sitter-plunt.*
    echo "Clean complete"
    exit 0
fi

# Generate parser if needed
if [ -f "$SRC_DIR/grammar.js" ] && [ ! -f "$SRC_DIR/parser.c" ]; then
    tree-sitter generate -C "$SRC_DIR"
fi

# Convert Unicode escapes to actual UTF-8 characters
if [ -f "$SRC_DIR/parser.c" ]; then
    python3 -c "
import re
with open('$SRC_DIR/parser.c', 'r', encoding='utf-8') as f:
    content = f.read()
def replace_unicode_escape(match):
    return chr(int(match.group(1), 16))
content = re.sub(r'\\\\u([0-9a-fA-F]{4})', replace_unicode_escape, content)
with open('$SRC_DIR/parser_utf8.c', 'w', encoding='utf-8') as f:
    f.write(content)
"
fi

mkdir -p "$OUTPUT_DIR"

# Use the UTF-8 converted parser if available
if [ -f "$SRC_DIR/parser_utf8.c" ]; then
    SRCS="$SRC_DIR/parser_utf8.c"
else
    SRCS="$SRC_DIR/parser.c"
fi
[ -f "$SRC_DIR/scanner.c" ] && SRCS="$SRCS $SRC_DIR/scanner.c"

# Compile with tree-sitter runtime and UTF-8 support
gcc -shared -fPIC -O2 -finput-charset=UTF-8 -fexec-charset=UTF-8 -I"$TS_RUNTIME/include" -o "$OUTPUT_DIR/libtree-sitter-plunt.so" $SRCS "$TS_RUNTIME/src/lib.c"

echo "Build complete: $OUTPUT_DIR"
