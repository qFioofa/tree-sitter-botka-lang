#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
INTERPRETER_DIR="$PROJECT_ROOT/interpreter"
BUILD_DIR="$PROJECT_ROOT/build"

if [ "$1" = "clean" ]; then
    rm -rf "$BUILD_DIR" "$INTERPRETER_DIR/bin" "$INTERPRETER_DIR/obj"
    echo "Clean complete"
    exit 0
fi

mkdir -p "$BUILD_DIR/bin"
cp "$PROJECT_ROOT/interpreter/bin/"*.so "$BUILD_DIR/bin/" 2>/dev/null || true
dotnet publish "$INTERPRETER_DIR/BotkaInterpreter.csproj" -c Release -o "$BUILD_DIR" --self-contained false
echo "Build complete: $BUILD_DIR"
