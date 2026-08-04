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
void UpdateStartscreen(State& currentState);
void UpdateChoicescreen(State& currentState,ArrowPosition& arrowPosition);
void UpdateTimerscreen(float& elapsedTime, bool& stopwatchRunning);
void DrawStartscreen(const Visuals& visuals,int eggCurrentFrame);
void DrawChoiceScreen(const Visuals& visuals,int arrowCurrentFrame,ArrowPosition arrowPosition);
void DrawTimerscreen(float elipsedTime, bool stopatchrunning);