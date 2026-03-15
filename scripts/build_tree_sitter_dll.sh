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

if [ -f "$SRC_DIR/grammar.js" ] && [ ! -f "$SRC_DIR/parser.c" ]; then
    tree-sitter generate -C "$SRC_DIR"
fi

mkdir -p "$OUTPUT_DIR"

SRCS="$SRC_DIR/parser.c"
[ -f "$SRC_DIR/scanner.c" ] && SRCS="$SRCS $SRC_DIR/scanner.c"

# Compile with tree-sitter runtime
gcc -shared -fPIC -O2 -I"$TS_RUNTIME/include" -o "$OUTPUT_DIR/libtree-sitter-plunt.so" $SRCS "$TS_RUNTIME/src/lib.c"

echo "Build complete: $OUTPUT_DIR"
