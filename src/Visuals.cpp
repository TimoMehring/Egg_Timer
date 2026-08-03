#include "Visuals.h"

Visuals LoadVisuals()
{
    Visuals visuals;

    visuals.egg = LoadTexture("assets/egg.png");
    visuals.egg_soft_boiled = LoadTexture("assets/egg_soft.png");
    visuals.egg_hard_boiled = LoadTexture("assets/egg_hard.png");
    visuals.arrow = LoadTexture("assets/arrow.png");

    return visuals;
}

void UnloadVisuals(Visuals& visuals)
{
    UnloadTexture(visuals.egg);
    UnloadTexture(visuals.egg_soft_boiled);
    UnloadTexture(visuals.egg_hard_boiled);
    UnloadTexture(visuals.arrow);
}