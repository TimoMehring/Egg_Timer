@echo off
cd /d "%~dp0"

if not exist release mkdir release

windres egg_icon_exe.rc -O coff -o egg_icon_exe.o

if %errorlevel% neq 0 (
    echo.
    echo Icon-Resource konnte nicht erstellt werden.
    pause
    exit /b %errorlevel%
)

g++ -std=c++17 -Wall -Wextra src/*.cpp egg_icon_exe.o -o release/EggTimer.exe -mwindows -lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++

if %errorlevel% neq 0 (
    echo.
    echo Release-Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

if exist release\assets rmdir /S /Q release\assets
xcopy assets release\assets\ /E /I /Y

del egg_icon_exe.o

echo.
echo Release erfolgreich erstellt.
echo Datei: release\EggTimer.exe
pause