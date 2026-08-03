#include "State.h"
#include "Visuals.h"

void UpdateStartscreen(State& currentState)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        currentState = State::Choicescreen;
    }
}

void DrawStartscreen(const Visuals& visuals, int eggCurrentFrame)
{
    ClearBackground(DARKBLUE);

    DrawText("EGG TIMER", 300, 150, 50, WHITE);
    DrawText("ENTER zum Starten", 310, 300, 25, LIGHTGRAY);
    DrawTextureEx(visuals.egg, Vector2{500.0f, 400.0f}, 0.0f, 10.0f, WHITE );

    // Egg_Spritesheet_Animation
    const float frameWidth_Egg_Spritesheet = 11.0f;
    const float frameHeight_Egg_Spritesheet = 17.0f;
    const float scale = 10.0f;

    // 
    const float eggWidth = frameWidth_Egg_Spritesheet * scale;
    const float eggHeight = frameHeight_Egg_Spritesheet * scale;
    
    const float eggX = (800.0f - eggWidth) / 2.0f;
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

    
    DrawText("CHOICE SCREEN", 250, 300, 40, WHITE);
    DrawTextureEx(visuals.egg_hard_boiled, Vector2 {200.0f, 500.0f}, 0.0, 10.0f, WHITE);
    DrawTextureEx(visuals.egg_soft_boiled, Vector2 {400.0f, 500.0f}, 0.0f, 10.0f, WHITE);

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
        arrowX = 200.0f;
        arrowY = 350.0f;
    }else if(arrowPosition == ArrowPosition::SoftBoiled){
        arrowX = 500.0f;
        arrowY = 350.0f;
    }

    Rectangle destination = {
        arrowX, arrowY, frameWidth_Arrow * scale, frameHeight_Arrow * scale
    };

    DrawTexturePro(visuals.arrow, source, destination, Vector2{0.0f, 0.0f}, 0.0f, WHITE);

};

void UpdateChoicescreen(State& currentState, ArrowPosition& arrowPosition){
    if(IsKeyPressed(KEY_LEFT)){
        arrowPosition = ArrowPosition::HardBoiled;
    }else if(IsKeyPressed(KEY_RIGHT)){
        arrowPosition = ArrowPosition::SoftBoiled;
    }
};