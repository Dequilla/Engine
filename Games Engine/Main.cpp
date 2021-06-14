#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>

#include "System/Window.hpp"
#include "System/Event.hpp"

void init() {
    SDL_SetMainReady();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
}

void exit() {
    SDL_Quit();
}

int main()
{
    init();
    
    eng::system::Window window("Game engine", { 1280, 720 });
    
    eng::system::Event e;
    bool quit = false;
    while (!quit) {
        while (eng::system::Event::poll(e)) {
            if (e.base.type == eng::system::Event::Type::QUIT) quit = true;
        }
    }

    exit();
    return 0;
}
