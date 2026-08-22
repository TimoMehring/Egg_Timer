#pragma once
#include "raylib.h"

struct Audio{
    Sound button;
};

Audio LoadAudio();
void UnloadAudio(Audio& audio);