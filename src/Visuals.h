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
    Texture2D resetButton;
}; 

enum class State;
//enum class TimerOnOff;


Visuals LoadVisuals();
void UnloadVisuals(Visuals& visuals);
void DrawHomeButton(Visuals visuals,State currentState);
void DrawStartStopButton(Visuals visuals);
void DrawResetButton(Visuals visuals);

void UpdateHomeButton(Visuals visuals, State& currentState);
void UpdateTimerScreenButtons(Visuals visuals, State& currentState, float& elapsedTime);