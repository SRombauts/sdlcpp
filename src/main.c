#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main(void)
{
    SDL_Surface* screen;
    if (-1 == SDL_Init(SDL_INIT_VIDEO)) 
    { 
        printf("Can't init SDL: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE);
    if (NULL == screen)
    {
        printf("Can't set video mode: %s", SDL_GetError());
        return EXIT_FAILURE; 
    }

    SDL_Delay(3000);

    return EXIT_SUCCESS;
}

