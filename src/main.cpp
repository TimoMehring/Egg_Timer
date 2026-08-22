#include "raylib.h"
#include "State.h"
#include "Visuals.h"

int main(){
    const int screenWidth = 545;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Egg Timer");
    SetTargetFPS(60);
    

    State currentState = State::Startscreen;
    ArrowPosition arrowPosition = ArrowPosition::HardBoiled;

    Visuals visuals = LoadVisuals();

    TimerOnOff timerOnOff = TimerOnOff::Pausing;

    int eggCurrentFrame = 0;
    const int eggFrameCount = 3;
    float eggFrameTimer = 0.0f;
    const float eggFrameDuration = 0.25f;

    // Arrow Animation
    int arrowCurrentFrame = 0;
    const int arrowFrameCount = 3;
    float arrowFrameTimer = 0.0f;
    const float arrowFrameDuration = 0.25f;

    float elapsedTime = 0.0f;
    bool stopwatchRunning = false;
    

    while(!WindowShouldClose()){
        eggFrameTimer += GetFrameTime();
        if(eggFrameTimer >= eggFrameDuration){
            eggFrameTimer = 0.0f;
            eggCurrentFrame++;

            if(eggCurrentFrame >= eggFrameCount){ 
                eggCurrentFrame = 0;
            }
        }

        arrowFrameTimer += GetFrameTime();
        if(arrowFrameTimer >= arrowFrameDuration){
            arrowFrameTimer = 0.0f;
            arrowCurrentFrame++;
            if(arrowCurrentFrame >= arrowFrameCount){
                arrowCurrentFrame = 0;
            }
        }
        
        if(currentState == State::Startscreen){
            UpdateStartscreen(currentState);
        }else if(currentState == State::Choicescreen){
            UpdateChoicescreen(currentState, arrowPosition);
            UpdateClickOnEgg(visuals, currentState, arrowPosition);
        }else if (currentState == State::Timerscreen){
            UpdateTimerscreen(elapsedTime, stopwatchRunning);
            if(IsKeyPressed(KEY_H)){
                elapsedTime = 0.0f;
                stopwatchRunning = false;
                currentState = State::Startscreen;
            }
            UpdateHomeButton(visuals,currentState);
            UpdateTimerScreenButtons(visuals, currentState, elapsedTime,stopwatchRunning, timerOnOff);
        }

        BeginDrawing();
        ClearBackground(BROWN);
        DrawTexture(visuals.wallpaper, 0, 0, WHITE);
        if(currentState == State::Startscreen){
            DrawStartscreen(visuals,eggCurrentFrame);
        }else if(currentState == State::Choicescreen){
            DrawChoiceScreen(visuals, arrowCurrentFrame, arrowPosition); 
        }else if (currentState == State::Timerscreen){
            DrawTimerscreen(visuals, arrowPosition,elapsedTime, stopwatchRunning);
            DrawStartStopButton(visuals,timerOnOff);
            DrawResetButton(visuals);
            DrawHomeButton(visuals,currentState);
        }




        //BeginDrawing();
        //ClearBackground(BROWN);
        EndDrawing();

    }
    UnloadVisuals(visuals);
    CloseWindow();
    return 0;
    

}