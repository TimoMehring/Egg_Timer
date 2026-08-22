@echo off
cd /d %~dp0

if not exist build mkdir build
if not exist release mkdir release
if not exist release\Egg_Timer_v1.0.0 mkdir release\Egg_Timer_v1.0.0

windres egg_icon_exe.rc -O coff -o build\egg_icon_exe.o

if %errorlevel% neq 0 (
    echo.
    echo Resource Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

g++ -std=c++17 -O2 ^
src/main.cpp ^
src/State.cpp ^
src/Visuals.cpp ^
src/audio.cpp ^
build\egg_icon_exe.o ^
-o release\Egg_Timer_v1.0.0\Egg_Timer.exe ^
-lraylib -lopengl32 -lgdi32 -lwinmm ^
-mwindows

if %errorlevel% neq 0 (
    echo.
    echo Release Build fehlgeschlagen.
    pause
    exit /b %errorlevel%
)

echo.
echo Release Build erfolgreich.
echo Datei: release\Egg_Timer_v1.0.0\Egg_Timer.exe
pause