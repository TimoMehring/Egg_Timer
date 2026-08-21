#include "Visuals.h"

Visuals LoadVisuals()
{
    Visuals visuals;
    visuals.wallpaper = LoadTexture("assets/wallpaper.png");
    visuals.egg_spritesheet = LoadTexture("assets/egg_spritesheet.png");
    visuals.egg_soft_boiled = LoadTexture("assets/egg_soft.png");
    visuals.egg_hard_boiled = LoadTexture("assets/egg_hard.png");
    visuals.arrow = LoadTexture("assets/arrow.png");

    visuals.homeButton = LoadTexture("assets/homebutton.png");
    visuals.startButton = LoadTexture("assets/startbutton.png");
    visuals.stopButton = LoadTexture("assets/stopbutton.png");

    return visuals;
}

void UnloadVisuals(Visuals& visuals)
{
    UnloadTexture(visuals.egg_soft_boiled);
    UnloadTexture(visuals.egg_hard_boiled);
    UnloadTexture(visuals.arrow);
    UnloadTexture(visuals.wallpaper);
    UnloadTexture(visuals.egg_spritesheet);

    UnloadTexture(visuals.homeButton);
    UnloadTexture(visuals.startButton);
    UnloadTexture(visuals.stopButton);
}

void DrawHomeButton(Visuals visuals, State currentState){
    DrawTextureEx(visuals.homeButton, {460.0f,530.0f},0.0f,5.0f,WHITE);
}

void DrawStartStopButton(Visuals visuals){
    DrawTextureEx(visuals.startButton, {200.0f, 200.0f}, 0.0f, 5.0f, WHITE);
}