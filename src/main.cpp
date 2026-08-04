#include "raylib.h"
#include "State.h"
#include "Visuals.h"

int main(){
    const int screenWidth = 545;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Egg Timer");
    

    State currentState = State::Startscreen;
    ArrowPosition arrowPosition = ArrowPosition::HardBoiled;
    SwitchAnimation status = SwitchAnimation::None;

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

    // SwitchAnimation
    int switchAnimationCurrentFrame = 0;
    const int switchAnimationFrameCount = 16;
    float switchAnimationFrameTimer = 0.0f;
    const float switchAnimationFrameDuration = 0.1f;

    
    // Terminal Debug Ausgabe für Ei Sprite
    TraceLog(LOG_INFO, "Egg width: %d", visuals.egg.width);
    TraceLog(LOG_INFO, "Egg height: %d", visuals.egg.height);
    TraceLog(LOG_INFO, "Egg id: %u", visuals.egg.id);

    

    while(!WindowShouldClose()){
        eggFrameTimer += GetFrameTime();
        if(eggFrameTimer >= eggFrameDuration){
            eggFrameTimer = 0.0f;
            eggCurrentFrame++;

            if(eggCurrentFrame >= eggFrameCount){ // >= eggFrameCount, Spritesheet(3Frames)
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

/*         switchAnimationFrameTimer += GetFrameTime();
        if(switchAnimationFrameTimer >= switchAnimationFrameDuration){
            switchAnimationFrameTimer = 0.0f;
            switchAnimationCurrentFrame++;
            if(switchAnimationCurrentFrame >= switchAnimationFrameCount){
                switchAnimationCurrentFrame = 0;
            }
        }
 */

        if(status != SwitchAnimation::None){
            switchAnimationFrameTimer += GetFrameTime();
             if (switchAnimationFrameTimer >= switchAnimationFrameDuration){
                switchAnimationFrameTimer = 0.0f;
                switchAnimationCurrentFrame++;
                if (switchAnimationCurrentFrame >= switchAnimationFrameCount){
                    switchAnimationCurrentFrame = 0;
                    status = SwitchAnimation::None;
                }

             }
        }
        
        if(currentState == State::Startscreen){
            UpdateStartscreen(currentState);
        }else if(currentState == State::Choicescreen){
            UpdateChoicescreen(currentState, arrowPosition, status, switchAnimationCurrentFrame, switchAnimationFrameTimer);
        }

        BeginDrawing();
        ClearBackground(BROWN);
        DrawTexture(visuals.wallpaper, 0, 0, WHITE);
        if(currentState == State::Startscreen){
            DrawStartscreen(visuals,eggCurrentFrame);
        }else if(currentState == State::Choicescreen){
            DrawChoiceScreen(visuals, arrowCurrentFrame, arrowPosition); 
        }

        if(status == SwitchAnimation::LeftToRight){
            DrawSideSwitch(visuals, switchAnimationCurrentFrame);
        }else if(status == SwitchAnimation::RightToLeft){
            // fehlt noch
        }



        //BeginDrawing();
        //ClearBackground(BROWN);
        EndDrawing();

    }
    UnloadVisuals(visuals);
    CloseWindow();
    return 0;
    

}