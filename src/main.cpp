#include <iostream>
#include "Image.h"
#include "Screen.h"

// Les paramètres de notre écran
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;


int main(void)
{
    bool        bRunning = true;
    int         res;
    SDL_Event   event;

    res = SDL_Init(SDL_INIT_VIDEO);
    if (-1 != res)
    {
        Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");

        Image image("res/background.bmp");
        Image sprite("res/sprite.bmp", 64, 48);

        while (bRunning)
        {

            while (SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_QUIT:
                        // Si l'évènement QUIT est levé
                        bRunning = false;
                        break;
                    case SDL_KEYDOWN:
                        // Si une touche est pressée
                        if (SDLK_ESCAPE == event.key.keysym.sym)
                        {
                            bRunning = false;
                        }
                        break;
                    default:
                        // Autre évènement
                        ;
                }
            }
            // Blitte l'image sur l'écran
            screen.blit(image);
            screen.blit(sprite);
            sprite.getOffset().x = (sprite.getOffset().x+ 1)%(640+64);

            // Mise à jour de l'écran
            screen.flip();
        }
        //SDL_Delay(3000);
    }
    else
    {
        std::cout << "Can't init SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

