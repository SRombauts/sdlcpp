#include <iostream>
#include "Image.h"
#include "Screen.h"

// Les paramètres de notre écran
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;


int main(void)
{
    int res;

    res = SDL_Init(SDL_INIT_VIDEO);
    if (-1 != res)
    {
        Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");

        Image image("res/background.bmp");

        // Blitte l'image sur l'écran
        screen.blit(image);

        // Mise à jour de l'écran
        screen.flip();

        SDL_Delay(3000);
    }
    else
    {
        std::cout << "Can't init SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

