#include "audio.h"

Audio LoadAudio(){
    Audio audio;
    audio.button = LoadSound("assets/button_sound.wav");
    audio.switchArrow = LoadSound("assets/switcharrow.wav");

    audio.theme = LoadMusicStream("assets/theme.wav");
    audio.theme.looping = true;

    return audio;
}

void UnloadAudio(Audio& audio){
    UnloadSound(audio.button);
    UnloadSound(audio.switchArrow);

    UnloadMusicStream(audio.theme);
}