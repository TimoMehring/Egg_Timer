#include "State.h"
#include "Visuals.h"

void UpdateStartscreen(State& currentState)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentState = State::Choicescreen;
    }
}

void DrawStartscreen(const Visuals& visuals)
{
    ClearBackground(DARKBLUE);

    DrawText("EGG TIMER", 300, 150, 50, WHITE);
    DrawText("ENTER zum Starten", 310, 300, 25, LIGHTGRAY);
    DrawTextureEx(visuals.egg, Vector2{500.0f, 400.0f}, 0.0f, 10.0f, WHITE );
}

void DrawChoiceScreen(){

};