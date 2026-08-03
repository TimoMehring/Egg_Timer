#include "raylib.h"
#include "State.h"
#include "Visuals.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Egg Timer");

    State currentState = State::Startscreen;

    Visuals visuals = LoadVisuals();
    
    // Terminal Debug Ausgabe für Ei Sprite
    TraceLog(LOG_INFO, "Egg width: %d", visuals.egg.width);
    TraceLog(LOG_INFO, "Egg height: %d", visuals.egg.height);
    TraceLog(LOG_INFO, "Egg id: %u", visuals.egg.id);

    

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BROWN);
        if(currentState == State::Startscreen){
            DrawStartscreen(visuals);
        }



        //BeginDrawing();
        //ClearBackground(BROWN);
        EndDrawing();

    }
    UnloadVisuals(visuals);
    CloseWindow();
    return 0;
    

}