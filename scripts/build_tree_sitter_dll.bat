@echo off
setlocal

set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%..
set SRC_DIR=%PROJECT_ROOT%\src
set OUTPUT_DIR=%PROJECT_ROOT%\interpreter\bin

if "%1"=="clean" (
    del /q "%OUTPUT_DIR%\tree-sitter-plunt.*" 2>nul
    echo Clean complete
    goto :end
)

if exist "%SRC_DIR%\grammar.js" (
    if not exist "%SRC_DIR%\parser.c" (
        cd /d "%SRC_DIR%" && tree-sitter generate && cd /d "%SCRIPT_DIR%"
    )
)

if not exist "%OUTPUT_DIR%" mkdir "%OUTPUT_DIR%"

set SRC_FILES=%SRC_DIR%\parser.c
if exist "%SRC_DIR%\scanner.c" set SRC_FILES=%SRC_FILES% %SRC_DIR%\scanner.c

gcc -shared -O2 -o "%OUTPUT_DIR%\tree-sitter-plunt.dll" %SRC_FILES%
echo Build complete: %OUTPUT_DIR%

:end
endlocal
