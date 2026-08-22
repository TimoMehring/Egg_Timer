#include "State.h"
#include "Visuals.h"
#include "audio.h"

void UpdateStartscreen(State& currentState,Audio& audio)
{
    if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        PlaySound(audio.button);
        currentState = State::Choicescreen;
    }
}

void DrawStartscreen(const Visuals& visuals, int eggCurrentFrame)
{
    ClearBackground(DARKBLUE);

    DrawText("EGG TIMER", 130, 150, 50, BLACK);
    DrawText("Press Enter or Click to start", 90, 220, 25, BLACK);

    // Egg_Spritesheet_Animation
    const float frameWidth_Egg_Spritesheet = 11.0f;
    const float frameHeight_Egg_Spritesheet = 17.0f;
    const float scale = 10.0f;

    // 
    const float eggWidth = frameWidth_Egg_Spritesheet * scale;
    const float eggHeight = frameHeight_Egg_Spritesheet * scale;
    
    const float eggX = (550.0f - eggWidth) / 2.0f;
    const float eggY = (800.0f - eggHeight) / 2.0f;


    Rectangle source = {
        eggCurrentFrame * frameWidth_Egg_Spritesheet, 0.0f, frameWidth_Egg_Spritesheet, frameHeight_Egg_Spritesheet
    };

    // const float scale = 10.0f;
    Rectangle destination = {
        eggX, eggY, frameWidth_Egg_Spritesheet*scale, frameHeight_Egg_Spritesheet*scale // 500.0f, 400.0f, frameWidth_Egg_Spritesheet*scale, frameHeight_Egg_Spritesheet*scale
    };

    DrawTexturePro(visuals.egg_spritesheet, source, destination, Vector2{0.0f, 0.0f}, 0.0f, WHITE);
}

void DrawChoiceScreen(const Visuals& visuals,int arrowCurrentFrame,ArrowPosition arrowPosition){
    ClearBackground(DARKBLUE);

    DrawTextureEx(visuals.egg_hard_boiled, Vector2 {100.0f, 350.0f}, 0.0, 10.0f, WHITE);
    //DrawText("Hard-Boiled",80.0f, 540.0f, 30, BLACK);
    DrawTextureEx(visuals.egg_soft_boiled, Vector2 {300.0f, 350.0f}, 0.0f, 10.0f, WHITE);

    // Arrow Attachments
    const float frameWidth_Arrow = 13.0f;
    const float frameHeight_Arrow = 18.0f;
    const float scale = 10.0f;

    Rectangle source = {arrowCurrentFrame * frameWidth_Arrow, 0.0f, frameWidth_Arrow, frameHeight_Arrow

    };

    // Anpassungen wegen Pfeil Soft or Boiled
    float arrowX = 200.0f;
    float arrowY = 350.0f;

    if(arrowPosition == ArrowPosition::HardBoiled){
        arrowX = 110.0f;
        arrowY = 160.0f;
        DrawText("Hard-Boiled",100.0f, 540.0f, 30, BLACK);
    }else if(arrowPosition == ArrowPosition::SoftBoiled){
        arrowX = 310.0f;
        arrowY = 160.0f;
        DrawText("Soft-Boiled",300.0f, 540.0f, 30, BLACK);
    }

    Rectangle destination = {
        arrowX, arrowY, frameWidth_Arrow * scale, frameHeight_Arrow * scale
    };

    DrawTexturePro(visuals.arrow, source, destination, Vector2{0.0f, 0.0f}, 0.0f, WHITE);

}

void UpdateChoicescreen(State& currentState,ArrowPosition& arrowPosition,Audio& audio){
    Rectangle buttonHardBoiled{
        0.0f, 0.0f,
        272.0f, 300.0f

    };
    Rectangle buttonSoftBoiled{
        273.0f, 0.0f,
        545.0f, 300.0f
    };

    Vector2 mousePosition = GetMousePosition();

    if (IsKeyPressed(KEY_LEFT) || (CheckCollisionPointRec(mousePosition, buttonHardBoiled) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))){
        PlaySound(audio.switchArrow);
        arrowPosition = ArrowPosition::HardBoiled;
    }else if (IsKeyPressed(KEY_RIGHT) || (CheckCollisionPointRec(mousePosition, buttonSoftBoiled) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))){
        PlaySound(audio.switchArrow);
        arrowPosition = ArrowPosition::SoftBoiled;
    }
    if(IsKeyPressed(KEY_ENTER)){
        PlaySound(audio.button);
        currentState = State::Timerscreen;
    }
 
}

void UpdateTimerscreen(float& elapsedTime, bool& stopwatchRunning){
    if(IsKeyPressed(KEY_SPACE)){
        stopwatchRunning = !stopwatchRunning;
    }
    if(IsKeyPressed(KEY_R)){
        elapsedTime = 0.0f;
    }
    if(stopwatchRunning){
        elapsedTime += GetFrameTime();
    }
}


void DrawTimerscreen(Visuals& visuals,ArrowPosition arrowPosition, float elapsedTime, bool stopwatchRunning){
    ClearBackground(DARKBLUE);
    int minutes = static_cast<int>(elapsedTime) / 60;
    int seconds = static_cast<int>(elapsedTime) % 60;
    int milliseconds =  static_cast<int>((elapsedTime - static_cast<int>(elapsedTime)) * 1000);

    DrawText(TextFormat("%02d:%02d:%03d", minutes, seconds, milliseconds), 135, 270, 60, BLACK);
    //DrawText(stopwatchRunning ? "SPACE: Pause" : "SPACE: Start",170,150,30,BLACK);
    //DrawText("R: Reset", 210, 400, 30, BLACK);
    //DrawText("H: Home Button", 20, 550, 20, BLACK);
    if(arrowPosition == ArrowPosition::HardBoiled){
        DrawTextureEx(visuals.HardBoiledSheet,{170.0f, 130.0f}, 0.0f, 2.0f, WHITE);
        DrawTextureEx(visuals.egg_hard_boiled, Vector2 {20.0f, 350.0f}, 0.0, 10.0f, WHITE);
        DrawText("Hard-Boiled",35.0f, 520.0f, 20, BLACK);
    }else if(arrowPosition == ArrowPosition::SoftBoiled){
        DrawTextureEx(visuals.SoftBoiledSheet,{170.0f, 130.0f}, 0.0f, 2.0f, WHITE);
        DrawTextureEx(visuals.egg_soft_boiled, Vector2 {20.0f, 350.0f}, 0.0f, 10.0f, WHITE);
        DrawText("Soft-Boiled",35.0f, 520.0f, 20, BLACK);
    }
    
}
