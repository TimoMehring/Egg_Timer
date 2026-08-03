#pragma once
#include "raylib.h"

enum class State{
    Startscreen,
    Choicescreen,

};
void UpdateStartscreen(State& currentState);
void DrawStartscreen();