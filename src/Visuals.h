#pragma once
#include "raylib.h"

struct Visuals {
    Texture2D egg_spritesheet;
    Texture2D egg_soft_boiled;
    Texture2D egg_hard_boiled;
    Texture2D arrow;
    Texture2D wallpaper;

    Texture2D homeButton;
    Texture2D startButton;
    Texture2D stopButton;
}; 

enum class State;
enum class TimerOnOff;


Visuals LoadVisuals();
void UnloadVisuals(Visuals& visuals);
void DrawHomeButton(Visuals visuals,State currentState);
void DrawStartStopButton(Visuals visuals);