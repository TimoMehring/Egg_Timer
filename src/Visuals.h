#pragma once
#include "raylib.h"
#include "audio.h"

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

    Texture2D HardBoiledSheet;
    Texture2D SoftBoiledSheet;
}; 



enum class State;
enum class TimerOnOff;
enum class ArrowPosition;


Visuals LoadVisuals();
void UnloadVisuals(Visuals& visuals);
void DrawHomeButton(Visuals visuals,State currentState);
void DrawStartStopButton(Visuals visuals,TimerOnOff& timerOnOff);
void DrawResetButton(Visuals visuals);

void UpdateHomeButton(Visuals visuals, State& currentState,Audio& audio);
void UpdateTimerScreenButtons(Visuals visuals, State& currentState, float& elapsedTime,bool& stopwatchRunning,TimerOnOff& timerOnOff,Audio& audio);
void UpdateClickOnEgg(Visuals visuals, State& currentState,ArrowPosition& arrowPosition,Audio& audio);