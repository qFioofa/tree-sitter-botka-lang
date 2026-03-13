@echo off
setlocal enabledelayedexpansion

set SCRIPT_DIR=%~dp0
set PROJECT_ROOT=%SCRIPT_DIR%..
set INTERPRETER_DIR=%PROJECT_ROOT%\interpreter
set BUILD_DIR=%PROJECT_ROOT%\build
set OUTPUT_NAME=BotkaInterpreter
set CSPROJ=%INTERPRETER_DIR%\BotkaInterpreter.csproj

echo ==============================================
echo   Build Plunt UML Interpreter
echo ==============================================
echo.

if "%1"=="clean" (
    call :clean
    goto :end
)

call :check_dependencies
call :create_build_dir
call :build
call :verify_output

echo.
echo [INFO] Build complete!
echo.
echo Output:
dir /b "%BUILD_DIR%"
goto :end

:check_dependencies
echo [INFO] Checking dependencies...
if not exist "%CSPROJ%" (
    echo [ERROR] File not found: %CSPROJ%
    echo [ERROR] Create it manually before building
    exit /b 1
)
where dotnet >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] dotnet CLI is required
    exit /b 1
)
echo [INFO] Dependencies OK
goto :eof

:create_build_dir
if not exist "%BUILD_DIR%" (
    mkdir "%BUILD_DIR%"
    echo [INFO] Created: %BUILD_DIR%
)
goto :eof

:build
echo [INFO] Building with dotnet...
dotnet publish "%CSPROJ%" -c Release -o "%BUILD_DIR%" --self-contained false
if %errorlevel% equ 0 (
    echo [INFO] Build successful
) else (
    echo [ERROR] Build failed
    exit /b 1
)
goto :eof

:verify_output
echo [INFO] Verifying output...
if exist "%BUILD_DIR%\%OUTPUT_NAME%.exe" (
    echo [INFO] Found: %BUILD_DIR%\%OUTPUT_NAME%.exe
)
if exist "%BUILD_DIR%\%OUTPUT_NAME%.dll" (
    echo [INFO] Found: %BUILD_DIR%\%OUTPUT_NAME%.dll
)
if not exist "%BUILD_DIR%\%OUTPUT_NAME%.exe" if not exist "%BUILD_DIR%\%OUTPUT_NAME%.dll" (
    echo [WARN] Executable not found in %BUILD_DIR%
)
goto :eof

:clean
echo [INFO] Cleaning...
rmdir /s /q "%BUILD_DIR%" 2>nul
rmdir /s /q "%INTERPRETER_DIR%\bin" 2>nul
rmdir /s /q "%INTERPRETER_DIR%\obj" 2>nul
echo [INFO] Clean complete
goto :eof

:end
endlocal
