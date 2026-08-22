#include "raylib.h"
#include "State.h"
#include "Visuals.h"
#include "audio.h"

int main(){
    const int screenWidth = 545;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Egg Timer");
    InitAudioDevice();

    Image icon = LoadImage("assets/egg_icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);
    SetTargetFPS(60);
    

    State currentState = State::Startscreen;
    ArrowPosition arrowPosition = ArrowPosition::HardBoiled;

    Visuals visuals = LoadVisuals();
    Audio audio = LoadAudio();

    PlayMusicStream(audio.theme);

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
        UpdateMusicStream(audio.theme);
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
            UpdateStartscreen(currentState,audio);
        }else if(currentState == State::Choicescreen){
            UpdateChoicescreen(currentState, arrowPosition,audio);
            UpdateClickOnEgg(visuals, currentState, arrowPosition,audio);
        }else if (currentState == State::Timerscreen){
            UpdateTimerscreen(elapsedTime, stopwatchRunning);
            if(IsKeyPressed(KEY_H)){
                elapsedTime = 0.0f;
                stopwatchRunning = false;
                currentState = State::Startscreen;
            }
            UpdateHomeButton(visuals,currentState,audio);
            UpdateTimerScreenButtons(visuals, currentState, elapsedTime,stopwatchRunning, timerOnOff, audio);
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




        EndDrawing();

    }
    UnloadVisuals(visuals);
    UnloadAudio(audio);
    CloseAudioDevice();
    CloseWindow();
    return 0;
    

}