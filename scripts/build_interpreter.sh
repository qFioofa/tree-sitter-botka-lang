#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
INTERPRETER_DIR="$PROJECT_ROOT/interpreter"
BUILD_DIR="$PROJECT_ROOT/build"
OUTPUT_NAME="BotkaInterpreter"
CSPROJ="$INTERPRETER_DIR/BotkaInterpreter.csproj"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log_info()    { echo -e "${GREEN}[INFO]${NC} $1"; }
log_warn()    { echo -e "${YELLOW}[WARN]${NC} $1"; }
log_error()   { echo -e "${RED}[ERROR]${NC} $1"; }

check_dependencies() {
    log_info "Checking dependencies..."

    if [ ! -f "$CSPROJ" ]; then
        log_error "File not found: $CSPROJ"
        log_error "Create it manually before building"
        exit 1
    fi

    if ! command -v dotnet &> /dev/null; then
        log_error "dotnet CLI is required"
        exit 1
    fi

    log_info "Dependencies OK"
}

create_build_dir() {
    if [ ! -d "$BUILD_DIR" ]; then
        mkdir -p "$BUILD_DIR"
        log_info "Created: $BUILD_DIR"
    fi
}

build() {
    log_info "Building with dotnet..."

    local abs_build_dir
    abs_build_dir="$(realpath "$BUILD_DIR")"

    dotnet publish "$CSPROJ" \
        -c Release \
        -o "$abs_build_dir" \
        --self-contained false

    if [ $? -eq 0 ]; then
        log_info "Build successful"
    else
        log_error "Build failed"
        exit 1
    fi
}

verify_output() {
    log_info "Verifying output..."

    local found=0
    for ext in "" ".exe" ".dll"; do
        if [ -f "$BUILD_DIR/${OUTPUT_NAME}${ext}" ]; then
            log_info "Found: $BUILD_DIR/${OUTPUT_NAME}${ext}"
            found=1
        fi
    done

    if [ $found -eq 0 ]; then
        log_warn "Executable not found in $BUILD_DIR"
        log_info "Searching for artifacts..."
        find "$INTERPRETER_DIR/bin" -name "${OUTPUT_NAME}*" -type f 2>/dev/null | head -5 || true
    fi
}

clean() {
    log_info "Cleaning..."
    rm -rf "$BUILD_DIR"
    rm -rf "$INTERPRETER_DIR/bin"
    rm -rf "$INTERPRETER_DIR/obj"
    log_info "Clean complete"
}

main() {
    echo "=============================================="
    echo "  Build Plunt UML Interpreter"
    echo "=============================================="
    echo ""

    log_info "Project root: $PROJECT_ROOT"
    log_info "Build dir: $BUILD_DIR"
    echo ""

    if [ "$1" = "clean" ]; then
        clean
        exit 0
    fi

    check_dependencies
    create_build_dir
    build
    verify_output

    echo ""
    log_info "Build complete!"
    echo ""
    echo "Output:"
    ls -la "$BUILD_DIR"
}

main "$@"
