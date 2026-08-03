#include "raylib.h"
#include "State.h"
#include "Visuals.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Egg Timer");

    State currentState = State::Startscreen;

    Visuals visuals = LoadVisuals();

    int eggCurrentFrame = 0;
    const int eggFrameCount = 3;
    float eggFrameTimer = 0.0f;
    const float eggFrameDuration = 0.25f;

    // Arrow Animation
    int arrowCurrentFrame = 0;
    const int arrowFrameCount = 3;
    float arrowFrameTimer = 0.0f;
    const float arrowFrameDuration = 0.25f;

    
    // Terminal Debug Ausgabe für Ei Sprite
    TraceLog(LOG_INFO, "Egg width: %d", visuals.egg.width);
    TraceLog(LOG_INFO, "Egg height: %d", visuals.egg.height);
    TraceLog(LOG_INFO, "Egg id: %u", visuals.egg.id);

    

    while(!WindowShouldClose()){
        eggFrameTimer += GetFrameTime();
        if(eggFrameTimer >= eggFrameDuration){
            eggFrameTimer = 0.0f;
            eggCurrentFrame++;

            if(eggCurrentFrame >= 4){ // >= eggFrameCount, Spritesheet(3Frames)
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
        }

        BeginDrawing();
        ClearBackground(BROWN);
        if(currentState == State::Startscreen){
            DrawStartscreen(visuals,eggCurrentFrame);
        }else if(currentState == State::Choicescreen){
            DrawChoiceScreen(visuals, arrowCurrentFrame); 
        }



        //BeginDrawing();
        //ClearBackground(BROWN);
        EndDrawing();

    }
    UnloadVisuals(visuals);
    CloseWindow();
    return 0;
    

}