#pragma once
#include "raylib.h"
#include "Visuals.h"

enum class State{
    Startscreen,
    Choicescreen,

};
void UpdateStartscreen(State& currentState);
void DrawStartscreen(const Visuals& visuals,int eggCurrentFrame);
void DrawChoicescreen();