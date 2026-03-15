@echo off
setlocal

if "%1"=="clean" (
    call scripts\build_tree_sitter_dll.bat clean
    call scripts\build_interpreter.bat clean
    echo Clean complete
    goto :end
)

call scripts\build_tree_sitter_dll.bat
if %errorlevel% neq 0 exit /b 1
call scripts\build_interpreter.bat
if %errorlevel% neq 0 exit /b 1
echo Build complete

:end
endlocal
