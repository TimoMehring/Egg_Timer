#include "raylib.h"
#include "State.h"
#include "Visuals.h"

int main(){
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Egg Timer");

    State currentState = State::Startscreen;

    Visuals visuals = LoadVisuals();

    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BROWN);
        if(currentState == State::Startscreen){
            DrawStartscreen();
        }



        //BeginDrawing();
        //ClearBackground(BROWN);
        EndDrawing();

    }
    UnloadVisuals(visuals);
    CloseWindow();
    return 0;
    

}