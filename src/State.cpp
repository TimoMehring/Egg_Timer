#include "State.h"

void UpdateStartscreen(State& currentState)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentState = State::Choicescreen;
    }
}

void DrawStartscreen()
{
    ClearBackground(DARKBLUE);

    DrawText("EGG TIMER", 300, 150, 50, WHITE);
    DrawText("ENTER zum Starten", 310, 300, 25, LIGHTGRAY);
}

