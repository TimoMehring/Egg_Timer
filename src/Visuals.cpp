#include "Visuals.h"
#include "State.h"

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
    visuals.resetButton = LoadTexture("assets/resetbutton.png");

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
    UnloadTexture(visuals.resetButton);
}

// Draw section

void DrawHomeButton(Visuals visuals, State currentState){
    DrawTextureEx(visuals.homeButton, {460.0f,530.0f},0.0f,5.0f,WHITE);
}

void DrawStartStopButton(Visuals visuals,TimerOnOff& timerOnOff){
    if(timerOnOff == TimerOnOff::Pausing){
        DrawTextureEx(visuals.startButton, {200.0f, 350.0f}, 0.0f, 5.0f, WHITE);
    }
    else if(timerOnOff == TimerOnOff::Running){
        DrawTextureEx(visuals.stopButton, {200.0f, 350.0f}, 0.0f, 5.0f, WHITE);
    }
    return;
}

void DrawResetButton(Visuals visuals){
    DrawTextureEx(visuals.resetButton, {200.0f, 450.0f}, 0.0f, 5.0f, WHITE);
}

// Update section
void UpdateHomeButton(Visuals visuals, State& currentState){
    Rectangle homeButton {
        460.0f, 530.0f, 
        static_cast<float>(visuals.startButton.width)*5.0f,
        static_cast<float>(visuals.startButton.height)*5.0f
    };

    Vector2 mousePosition = GetMousePosition();

    if(CheckCollisionPointRec(mousePosition,homeButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){

        currentState = State::Startscreen;
    }
}

void UpdateTimerScreenButtons(Visuals visuals, State& currentState, float& elapsedTime,bool& stopwatchRunning,TimerOnOff& timerOnOff){
    Rectangle ResetButton {
        200.0f, 450.0f,
        static_cast<float>(visuals.resetButton.width)*5.0f,
        static_cast<float>(visuals.resetButton.height)*5.0f
    };

    Rectangle StartStopButton {
        200.0f, 350.0f,
        static_cast<float>(visuals.startButton.width)*5.0f,
        static_cast<float>(visuals.startButton.height)*5.0f
    };

    Vector2 mousePosition = GetMousePosition();

    if(CheckCollisionPointRec(mousePosition,ResetButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        elapsedTime = 0.0f;
    }

    if(CheckCollisionPointRec(mousePosition, StartStopButton) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        stopwatchRunning = !stopwatchRunning;

        if(stopwatchRunning){
            timerOnOff = TimerOnOff::Running;
        }
        else{
            timerOnOff = TimerOnOff::Pausing;
        }
    }

}

void UpdateClickOnEgg(Visuals visuals, State& currentState){
    Rectangle HardBoiled{
        100.0f, 350.0f,
        static_cast<float>(visuals.egg_hard_boiled.width)*10.0f,
        static_cast<float>(visuals.egg_hard_boiled.height)*10.0f

    };

    Rectangle SoftBoiled{
        300.0f, 350.0f,
        static_cast<float>(visuals.egg_soft_boiled.width)*10.0f,
        static_cast<float>(visuals.egg_soft_boiled.height)*10.0f
    };

    Vector2 mousePosition = GetMousePosition();

    if(CheckCollisionPointRec(mousePosition,HardBoiled) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        currentState = State::Timerscreen;
    }
    if(CheckCollisionPointRec(mousePosition,SoftBoiled) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
        currentState = State::Timerscreen;
    }

}