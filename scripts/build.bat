@echo off
setlocal

set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%.

echo ==============================================
echo   Build Plunt UML - Complete Build
echo ==============================================
echo.

echo [INFO] Project root: %PROJECT_ROOT%
echo.

if "%1"=="clean" (
    echo [INFO] Running clean build...
    call scripts\build_tree_sitter_dll.bat clean
    call scripts\build_interpreter.bat clean
    echo.
    echo [INFO] Clean complete!
    goto :end
)

echo [INFO] Step 1/2: Building Tree-sitter parser library...
echo ----------------------------------------------
call scripts\build_tree_sitter_dll.bat
if %errorlevel% neq 0 (
    echo [ERROR] Parser build failed
    exit /b 1
)
echo.

echo [INFO] Step 2/2: Building C# interpreter...
echo ----------------------------------------------
call scripts\build_interpreter.bat
if %errorlevel% neq 0 (
    echo [ERROR] Interpreter build failed
    exit /b 1
)
echo.

echo ==============================================
echo [INFO] Build complete!
echo ==============================================
echo.
echo Output files:
echo   Parser library: %PROJECT_ROOT%interpreter\bin\
echo   Interpreter:    %PROJECT_ROOT%build\
echo.
echo To run:
echo   build\BotkaInterpreter.exe
echo.

:end
endlocal
