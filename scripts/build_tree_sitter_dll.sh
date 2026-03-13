#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
SRC_DIR="$PROJECT_ROOT/src"
OUTPUT_DIR="$PROJECT_ROOT/interpreter/bin"
PARSER_NAME="tree-sitter-plunt"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

log_info()    { echo -e "${GREEN}[INFO]${NC} $1"; }
log_warn()    { echo -e "${YELLOW}[WARN]${NC} $1"; }
log_error()   { echo -e "${RED}[ERROR]${NC} $1"; }

detect_platform() {
    case "$(uname -s)" in
        Linux*)     echo "linux" ;;
        Darwin*)    echo "macos" ;;
        MINGW*|MSYS*|CYGWIN*) echo "windows" ;;
        *)          echo "unknown" ;;
    esac
}

get_compiler_settings() {
    local platform="$1"
    case "$platform" in
        linux)
            CC="gcc"
            LIB_EXT="so"
            LIB_PREFIX="lib"
            CFLAGS="-shared -fPIC -O2"
            ;;
        macos)
            CC="clang"
            LIB_EXT="dylib"
            LIB_PREFIX="lib"
            CFLAGS="-shared -O2"
            ;;
        windows)
            CC="gcc"
            LIB_EXT="dll"
            LIB_PREFIX=""
            CFLAGS="-shared -O2"
            ;;
        *)
            log_error "Unknown platform: $platform"
            exit 1
            ;;
    esac
}

check_dependencies() {
    log_info "Checking dependencies..."
    if ! command -v gcc &> /dev/null && ! command -v clang &> /dev/null; then
        log_error "No C compiler found (gcc or clang required)"
        exit 1
    fi
    if ! command -v tree-sitter &> /dev/null; then
        log_warn "tree-sitter CLI not found. Assuming parser.c already exists."
    fi
    log_info "Dependencies OK"
}

generate_parser() {
    if [ -f "$SRC_DIR/grammar.js" ] && [ ! -f "$SRC_DIR/parser.c" ]; then
        log_info "Generating parser from grammar.js..."
        if command -v tree-sitter &> /dev/null; then
            (cd "$SRC_DIR" && tree-sitter generate)
        else
            log_error "tree-sitter CLI required to generate parser"
            exit 1
        fi
    fi
}

build_library() {
    local platform="$1"
    local cc="$2"
    local cflags="$3"
    local lib_prefix="$4"
    local lib_ext="$5"

    local lib_name="${lib_prefix}${PARSER_NAME}.${lib_ext}"
    local output_path="$OUTPUT_DIR/$lib_name"

    log_info "Building library: $lib_name"
    mkdir -p "$OUTPUT_DIR"

    local src_files="$SRC_DIR/parser.c"
    if [ -f "$SRC_DIR/scanner.c" ]; then
        src_files="$src_files $SRC_DIR/scanner.c"
        log_info "Including external scanner"
    fi

    local ts_runtime=""
    if [ -f "$PROJECT_ROOT/tree-sitter/lib/tree-sitter/parser.h" ]; then
        ts_runtime="-I$PROJECT_ROOT/tree-sitter/lib"
    fi

    log_info "Compiling with: $cc $cflags"
    $cc $cflags $ts_runtime -o "$output_path" $src_files

    if [ $? -eq 0 ]; then
        log_info "Build successful: $output_path"
    else
        log_error "Build failed"
        exit 1
    fi
}

clean() {
    log_info "Cleaning build artifacts..."
    rm -f "$OUTPUT_DIR"/${PARSER_NAME}.*
    log_info "Clean complete"
}

main() {
    local platform="${1:-$(detect_platform)}"

    echo "=============================================="
    echo "  Build Tree-sitter Parser for Plunt UML"
    echo "=============================================="
    echo ""

    log_info "Platform: $platform"
    log_info "Output directory: $OUTPUT_DIR"
    echo ""

    if [ "$1" = "clean" ]; then
        clean
        exit 0
    fi

    check_dependencies
    generate_parser
    get_compiler_settings "$platform"
    build_library "$platform" "$CC" "$CFLAGS" "$LIB_PREFIX" "$LIB_EXT"

    echo ""
    log_info "Build complete!"
    echo ""
    echo "Output file:"
    echo "  - $OUTPUT_DIR/${LIB_PREFIX}${PARSER_NAME}.${LIB_EXT}"
}

main "$@"
