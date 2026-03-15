#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

if [ "$1" = "clean" ]; then
    "$SCRIPT_DIR/build_tree_sitter_dll.sh" clean
    "$SCRIPT_DIR/build_interpreter.sh" clean
    echo "Clean complete"
    exit 0
fi

"$SCRIPT_DIR/build_tree_sitter_dll.sh"
"$SCRIPT_DIR/build_interpreter.sh"
echo "Build complete"
