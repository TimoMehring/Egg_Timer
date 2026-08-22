#include "audio.h"

Audio LoadAudio(){
    Audio audio;
    audio.button = LoadSound("assets/button_sound.wav");

    return audio;
}

void UnloadAudio(Audio& audio){
    UnloadSound(audio.button);
}