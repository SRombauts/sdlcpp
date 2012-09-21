#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

// Les paramètres de notre écran 
const int SCREEN_WIDTH  = 640; 
const int SCREEN_HEIGHT = 480; 
const int SCREEN_BPP    = 32;

int main(void)
{
    SDL_Surface* screen;
    if (-1 == SDL_Init(SDL_INIT_VIDEO))
    { 
        printf("Can't init SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE);
    if (NULL == screen)
    {
        printf("Can't set video mode: %s\n", SDL_GetError());
        return EXIT_FAILURE; 
    }

    // Mise en place de la barre de titre
    SDL_WM_SetCaption( "Hello World", NULL );

    // Surface tampon qui nous servira pour charger l'image
    SDL_Surface* loadedImage = NULL;
    // Chargement de l'image
    loadedImage = SDL_LoadBMP( "res/background.bmp" );
    // Si le chargement se passe bien
    if (NULL != loadedImage)
    {
        // On blitte la surface sur l'écran
        int err = SDL_BlitSurface(loadedImage, NULL, screen, NULL);
        if (0 == err)
        {
            // Mise à jour de l'écran
            if (-1 == SDL_Flip( screen)) {
                printf("Flip error: %s\n", SDL_GetError());
            }
        }
        else
        {
            printf("Blit error: %s\n", SDL_GetError());
        }
    }
    else
    {
        printf("Load error: %s\n", SDL_GetError());
    }

    SDL_Delay(3000);

    return EXIT_SUCCESS;
}

