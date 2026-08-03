#include "raylib.h"
#include "State.h"

int main(){
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Egg Timer");

    State currentState = State::Startscreen;

    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BROWN);
        EndDrawing();

    }
    CloseWindow();
    return 0;
    

}