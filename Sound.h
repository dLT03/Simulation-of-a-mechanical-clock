#pragma once
#include "Libraries.h"

bool initializeSDLAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

Mix_Chunk* loadTickSound() {
    Mix_Chunk* tickSound = Mix_LoadWAV("tic.wav");
    if (tickSound == NULL) {
        std::cerr << "Failed to load tick sound: " << Mix_GetError() << std::endl;
    }
    return tickSound;
}

void playTickSound(Mix_Chunk* tickSound) {
    if (tickSound != NULL) {
        Mix_PlayChannel(-1, tickSound, 0);
    }
}

void cleanupSDLAudio() {
    Mix_CloseAudio();
    SDL_Quit();
}
