#include "audio.h"

Audio LoadAudio(){
    Audio audio;
    audio.button = LoadSound("assets/button_sound.wav");
    audio.theme = LoadMusicStream("assets/theme.wav");
    audio.theme.looping = true;

    return audio;
}

void UnloadAudio(Audio& audio){
    UnloadSound(audio.button);
    UnloadMusicStream(audio.theme);
}