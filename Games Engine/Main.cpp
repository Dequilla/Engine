#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>

#include "System/Window.hpp"

int main()
{
    SDL_SetMainReady();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    
    eng::system::Window window("Game engine", { 1280, 720 }, { 100, 100 }, eng::system::Window::Flags::VISIBLE);
    
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_Quit();
    return 0;
}
