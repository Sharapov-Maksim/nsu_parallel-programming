@echo off
setlocal

REM Check if the index argument is provided
if "%~1"=="" (
    echo Usage: %0 index
    exit /b 1
)

REM Get the index argument
set "index=%~1"

REM Define the file names
set "resultFile=tests\test%index%.txt.result"
set "expectedFile=tests\test%index%.txt.expected"

REM Compare the files
fc "%resultFile%" "%expectedFile%" > nul
if %errorlevel% equ 0 (
    echo Test %index%. OK
) else (
    echo Test %index%. FAIL
)

endlocal