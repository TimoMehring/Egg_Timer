#pragma once
#include "raylib.h"

struct Audio{
    Sound button;
    Sound switchArrow;
    Music theme;
};

Audio LoadAudio();
void UnloadAudio(Audio& audio);