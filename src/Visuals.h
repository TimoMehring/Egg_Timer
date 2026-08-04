#pragma once
#include "raylib.h"

struct Visuals {
    Texture2D egg;
    Texture2D egg_spritesheet;
    Texture2D egg_soft_boiled;
    Texture2D egg_hard_boiled;
    Texture2D arrow;
    Texture2D wallpaper;
    Texture2D LeftToRight;
    Texture2D RightToLeft;


    
}; 

enum class SwitchAnimation{
    None,
    LeftToRight,
    RightToLeft,
};


void DrawSideSwitch(const Visuals& visuals, int switchAnimationCurrentFrame);
Visuals LoadVisuals();
void UnloadVisuals(Visuals& visuals);