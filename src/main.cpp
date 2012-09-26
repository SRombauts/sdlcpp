#include <iostream>
#include "Image.h"
#include "Screen.h"
#include "Position.h"


// Les paramètres de notre écran
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* argv[])
{
    bool        bRunning = true;
    int         res;
    SDL_Event   event;

    for (int arg = 0; arg < argc; arg++)
    {
        printf("%s", argv[arg]);
    }

    res = SDL_Init(SDL_INIT_VIDEO);
    if (-1 != res)
    {
        Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");

        Image background("res/background.bmp");
        Image sprite    ("res/sprite.bmp", true);
        Position position(64, 48);

        Uint32 fpsTick  = SDL_GetTicks();
        Uint32 lastTick = SDL_GetTicks();
        Uint32 nbFrame  = 0;
        Uint32 fps = 0;
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
                    case SDL_MOUSEMOTION:
                        if (event.motion.state & SDL_BUTTON(1)) // Bouton Gauche appuyé
                        {
                            position.set ((Sint16)(event.motion.x - sprite.getSurface().w/2),
                                          (Sint16)(event.motion.y - sprite.getSurface().h/2));
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        position.set ((Sint16)(event.motion.x - sprite.getSurface().w/2),
                                      (Sint16)(event.motion.y - sprite.getSurface().h/2));
                        break;
                    default:
                        // Autre évènement
                        ;
                }
            }
            // Incrémente le déplacement du sprite, et le limite à l'affichage sur l'écran
            position.incr(5, 0);
            // TODO sprite.getOffset().x = (sprite.getOffset().x) % (screen.getSurface().w);
            if (position.getRect().x >= (screen.getSurface().w))
            {
                position.getRect().x = 0;
            }

            // Blit le background puis le sprite sur l'écran (en double buffering)
            screen.blit(background);
            screen.blit(sprite, position);

            // Mise à jour de l'écran (utilise le double buffering)
            screen.flip();

            // Calcul du framerate
            nbFrame++;
            Uint32 currentTick  = SDL_GetTicks();
            // Met à jour l'indicateur de FPS seulement une fois par seconde
            Uint32 deltaFpsTick = (currentTick - fpsTick);
            if (1000 < deltaFpsTick)
            {
                fps = (nbFrame*1000)/deltaFpsTick;
                std::cout << fps << std::endl;

                fpsTick = currentTick;
                nbFrame = 0;
            }

            // Lissage du framerate vers 30 fps (33ms par frame)
            Uint32 deltaTick = (currentTick - lastTick);
            if (deltaTick < 33)
            {
                SDL_Delay(33 - deltaTick);
            }
            lastTick    = currentTick;
        }
    }
    else
    {
        std::cout << "Can't init SDL: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}

