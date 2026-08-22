#pragma once
#include "raylib.h"
#include "Visuals.h"

enum class ArrowPosition{
    HardBoiled,
    SoftBoiled,
};

enum class State{
    Startscreen,
    Choicescreen,
    Timerscreen

};

enum class TimerOnOff{
    Running,
    Pausing
};

void UpdateStartscreen(State& currentState,Audio& audio);
void UpdateChoicescreen(State& currentState,ArrowPosition& arrowPosition,Audio& audio);
void UpdateTimerscreen(float& elapsedTime, bool& stopwatchRunning);
void DrawStartscreen(const Visuals& visuals,int eggCurrentFrame);
void DrawChoiceScreen(const Visuals& visuals,int arrowCurrentFrame,ArrowPosition arrowPosition);
void DrawTimerscreen(Visuals& visuals,ArrowPosition arrowPosition, float elapsedTime, bool stopwatchRunning);
