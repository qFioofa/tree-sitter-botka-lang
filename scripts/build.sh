#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log_info()  { echo -e "${GREEN}[INFO]${NC} $1"; }
log_warn()  { echo -e "${YELLOW}[WARN]${NC} $1"; }
log_error() { echo -e "${RED}[ERROR]${NC} $1"; }

echo "=============================================="
echo "  Build Plunt UML - Complete Build"
echo "=============================================="
echo ""

log_info "Project root: $PROJECT_ROOT"
echo ""

if [ "$1" = "clean" ]; then
    log_info "Running clean build..."
    ./scripts/build_tree_sitter_dll.sh clean
    ./scripts/build_interpreter.sh clean
    echo ""
    log_info "Clean complete!"
    exit 0
fi

log_info "Step 1/2: Building Tree-sitter parser library..."
echo "----------------------------------------------"
./scripts/build_tree_sitter_dll.sh
echo ""

log_info "Step 2/2: Building C# interpreter..."
echo "----------------------------------------------"
./scripts/build_interpreter.sh
echo ""

echo "=============================================="
log_info "Build complete!"
echo "=============================================="
echo ""
echo "Output files:"
echo "  Parser library: $PROJECT_ROOT/interpreter/bin/"
echo "  Interpreter:    $PROJECT_ROOT/build/"
echo ""
echo "To run:"
echo "  ./build/BotkaInterpreter"
echo ""
