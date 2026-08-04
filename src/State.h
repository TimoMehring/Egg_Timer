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

};
void UpdateStartscreen(State& currentState);
void UpdateChoicescreen(State& currentState, ArrowPosition& arrowPosition,SwitchAnimation& status,int& switchAnimationCurrentFrame,float& switchAnimationFrameTimer);
void DrawStartscreen(const Visuals& visuals,int eggCurrentFrame);
void DrawChoiceScreen(const Visuals& visuals,int arrowCurrentFrame,ArrowPosition arrowPosition);