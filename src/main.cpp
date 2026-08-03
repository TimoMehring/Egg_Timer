#include "raylib.h"

int main(){
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Fußballspiel Test");

    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BROWN);
        EndDrawing();

    }
    CloseWindow();
    return 0;
    

}