#include "Visuals.h"

Visuals LoadVisuals()
{
    Visuals visuals;
    visuals.wallpaper = LoadTexture("assets/wallpaper.png");
    visuals.LeftToRight = LoadTexture("assets/switchAnimation_LeftToRight.png");
    //visuals.RightToLeft = LoadTexture("assets/side_switch_rightToLeft_spritesheet.png");
    visuals.egg = LoadTexture("assets/egg.png");
    visuals.egg_spritesheet = LoadTexture("assets/egg_spritesheet.png");
    visuals.egg_soft_boiled = LoadTexture("assets/egg_soft.png");
    visuals.egg_hard_boiled = LoadTexture("assets/egg_hard.png");
    visuals.arrow = LoadTexture("assets/arrow.png");

    return visuals;
}

void DrawSideSwitch(const Visuals& visuals, int switchAnimationCurrentFrame){
    const float frameWidth_SwitchAnimation = 384.0f;
    const float frameHeight_SwitchAnimation = 33.0f;
    const float scale = 1.0f;

    Rectangle source = {
        switchAnimationCurrentFrame * frameWidth_SwitchAnimation, 0.0f, frameWidth_SwitchAnimation, frameHeight_SwitchAnimation
    };

    Rectangle destination = {
        73.0f, 553.0f, frameWidth_SwitchAnimation * scale, frameHeight_SwitchAnimation * scale // 500.0f, 400.0f, frameWidth_Egg_Spritesheet*scale, frameHeight_Egg_Spritesheet*scale
    };

    DrawTexturePro(visuals.LeftToRight, source, destination, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
}

void UnloadVisuals(Visuals& visuals)
{
    UnloadTexture(visuals.egg);
    UnloadTexture(visuals.egg_soft_boiled);
    UnloadTexture(visuals.egg_hard_boiled);
    UnloadTexture(visuals.arrow);
    UnloadTexture(visuals.wallpaper);
    UnloadTexture(visuals.LeftToRight);
    UnloadTexture(visuals.egg_spritesheet);
}