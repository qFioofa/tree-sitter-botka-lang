@echo off
setlocal

set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%..
set INTERPRETER_DIR=%PROJECT_ROOT%\interpreter
set BUILD_DIR=%PROJECT_ROOT%\build

if "%1"=="clean" (
    rmdir /s /q "%BUILD_DIR%" "%INTERPRETER_DIR%\bin" "%INTERPRETER_DIR%\obj" 2>nul
    echo Clean complete
    goto :end
)

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"
dotnet publish "%INTERPRETER_DIR%\BotkaInterpreter.csproj" -c Release -o "%BUILD_DIR%" --self-contained false
echo Build complete: %BUILD_DIR%

:end
endlocal
