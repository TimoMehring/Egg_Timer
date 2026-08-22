#pragma once
#include "raylib.h"

struct Audio{
    Sound button;
    Music theme;
};

Audio LoadAudio();
void UnloadAudio(Audio& audio);