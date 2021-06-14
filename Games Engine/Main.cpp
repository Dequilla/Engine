﻿#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <stdio.h>

int main()
{
    SDL_SetMainReady();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    
    SDL_Window* win = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);
    
    while (1)
        ;

    return 0;
}
