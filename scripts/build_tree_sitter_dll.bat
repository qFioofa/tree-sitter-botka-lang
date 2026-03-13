@echo off
setlocal enabledelayedexpansion

set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%..
set SRC_DIR=%PROJECT_ROOT%\src
set OUTPUT_DIR=%PROJECT_ROOT%\interpreter\bin
set PARSER_NAME=tree-sitter-plunt

echo ==============================================
echo   Build Tree-sitter Parser for Plunt UML
echo ==============================================
echo.

if "%1"=="clean" (
    call :clean
    goto :end
)

call :check_dependencies
call :generate_parser
call :build_library

echo.
echo [INFO] Build complete!
echo.
echo Output file:
echo   - %OUTPUT_DIR%\%PARSER_NAME%.dll
goto :end

:check_dependencies
echo [INFO] Checking dependencies...
where gcc >nul 2>&1
if %errorlevel% neq 0 (
    where clang >nul 2>&1
    if %errorlevel% neq 0 (
        echo [ERROR] No C compiler found (gcc or clang required)
        exit /b 1
    )
)
where tree-sitter >nul 2>&1
if %errorlevel% neq 0 (
    echo [WARN] tree-sitter CLI not found. Assuming parser.c already exists.
)
echo [INFO] Dependencies OK
goto :eof

:generate_parser
if exist "%SRC_DIR%\grammar.js" (
    if not exist "%SRC_DIR%\parser.c" (
        echo [INFO] Generating parser from grammar.js...
        where tree-sitter >nul 2>&1
        if %errorlevel% equ 0 (
            cd /d "%SRC_DIR%"
            tree-sitter generate
            cd /d "%SCRIPT_DIR%"
        ) else (
            echo [ERROR] tree-sitter CLI required to generate parser
            exit /b 1
        )
    )
)
goto :eof

:build_library
echo [INFO] Building library: %PARSER_NAME%.dll
if not exist "%OUTPUT_DIR%" (
    mkdir "%OUTPUT_DIR%"
)

set SRC_FILES=%SRC_DIR%\parser.c
if exist "%SRC_DIR%\scanner.c" (
    set SRC_FILES=%SRC_FILES% %SRC_DIR%\scanner.c
    echo [INFO] Including external scanner
)

gcc -shared -O2 -o "%OUTPUT_DIR%\%PARSER_NAME%.dll" %SRC_FILES%
if %errorlevel% equ 0 (
    echo [INFO] Build successful: %OUTPUT_DIR%\%PARSER_NAME%.dll
) else (
    echo [ERROR] Build failed
    exit /b 1
)
goto :eof

:clean
echo [INFO] Cleaning build artifacts...
del /q "%OUTPUT_DIR%\%PARSER_NAME%.*" 2>nul
echo [INFO] Clean complete
goto :eof

:end
endlocal
