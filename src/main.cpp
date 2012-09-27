#include <iostream>
#include "Animation.h"
#include "Image.h"
#include "Screen.h"
#include "Sprite.h"
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

        Image       background  ("res/background.bmp");
        Image::Ptr  imagePtr    (new Image("res/sprite.bmp", true));
        Sprite::Ptr spritePtr   (new Sprite(imagePtr, 7, 10, 50, 100));
        Position    position    (64, 48);
        Image::Ptr  planchePtr  (new Image("res/animation.bmp", true));
        Sprite::Ptr spriteUp0Ptr  (new Sprite(planchePtr,    0, 32, 32, 64));
        Sprite::Ptr spriteUp3Ptr  (new Sprite(planchePtr,   32, 32, 32, 64));
        Sprite::Ptr spriteUp2Ptr  (new Sprite(planchePtr, 2*32, 32, 32, 64));
        Sprite::Ptr spriteUp1Ptr  (new Sprite(planchePtr, 3*32, 32, 32, 64));
        Sprite::Ptr spriteUp4Ptr  (new Sprite(planchePtr, 4*32, 32, 32, 64));
        Sprite::Ptr spriteUp5Ptr  (new Sprite(planchePtr, 5*32, 32, 32, 64));
        Animation::Ptr animationUpPtr (new Animation(spriteUp1Ptr));
        animationUpPtr->addSprite (spriteUp2Ptr);
        animationUpPtr->addSprite (spriteUp3Ptr);
        animationUpPtr->addSprite (spriteUp1Ptr);
        animationUpPtr->addSprite (spriteUp4Ptr);
        animationUpPtr->addSprite (spriteUp5Ptr);
        animationUpPtr->setIndex(0);
        Sprite::Ptr spriteDown0Ptr  (new Sprite(planchePtr,    0, 32+64, 32, 64));
        Sprite::Ptr spriteDown3Ptr  (new Sprite(planchePtr,   32, 32+64, 32, 64));
        Sprite::Ptr spriteDown2Ptr  (new Sprite(planchePtr, 2*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown1Ptr  (new Sprite(planchePtr, 3*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown4Ptr  (new Sprite(planchePtr, 4*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown5Ptr  (new Sprite(planchePtr, 5*32, 32+64, 32, 64));
        Animation::Ptr animationDownPtr (new Animation(spriteDown1Ptr));
        animationDownPtr->addSprite (spriteDown2Ptr);
        animationDownPtr->addSprite (spriteDown3Ptr);
        animationDownPtr->addSprite (spriteDown1Ptr);
        animationDownPtr->addSprite (spriteDown4Ptr);
        animationDownPtr->addSprite (spriteDown5Ptr);
        animationDownPtr->setIndex(1);
        Sprite::Ptr spriteRight0Ptr  (new Sprite(planchePtr,    0, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight3Ptr  (new Sprite(planchePtr,   32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight2Ptr  (new Sprite(planchePtr, 2*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight1Ptr  (new Sprite(planchePtr, 3*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight4Ptr  (new Sprite(planchePtr, 4*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight5Ptr  (new Sprite(planchePtr, 5*32, 32+2*64, 32, 64));
        Animation::Ptr animationRightPtr (new Animation(spriteRight1Ptr));
        animationRightPtr->addSprite (spriteRight2Ptr);
        animationRightPtr->addSprite (spriteRight3Ptr);
        animationRightPtr->addSprite (spriteRight1Ptr);
        animationRightPtr->addSprite (spriteRight4Ptr);
        animationRightPtr->addSprite (spriteRight5Ptr);
        animationRightPtr->setIndex(2);
        Sprite::Ptr spriteLeft0Ptr  (new Sprite(planchePtr,    0, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft3Ptr  (new Sprite(planchePtr,   32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft2Ptr  (new Sprite(planchePtr, 2*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft1Ptr  (new Sprite(planchePtr, 3*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft4Ptr  (new Sprite(planchePtr, 4*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft5Ptr  (new Sprite(planchePtr, 5*32, 32+3*64, 32, 64));
        Animation::Ptr animationLeftPtr (new Animation(spriteLeft1Ptr));
        animationLeftPtr->addSprite (spriteLeft2Ptr);
        animationLeftPtr->addSprite (spriteLeft3Ptr);
        animationLeftPtr->addSprite (spriteLeft1Ptr);
        animationLeftPtr->addSprite (spriteLeft4Ptr);
        animationLeftPtr->addSprite (spriteLeft5Ptr);
        animationLeftPtr->setIndex(3);
        Position    positionFixeUp(0, 200);
        Position    positionFixeDown(100, 200);
        Position    positionFixeRight(200, 200);
        Position    positionFixeLeft(300, 200);

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
                            position.set ((Sint16)(event.motion.x - spritePtr->getSurface().getSurface().w/2),
                                          (Sint16)(event.motion.y - spritePtr->getSurface().getSurface().h/2));
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        position.set ((Sint16)(event.motion.x - spritePtr->getSurface().getSurface().w/2),
                                      (Sint16)(event.motion.y - spritePtr->getSurface().getSurface().h/2));
                        break;
                    default:
                        // Autre évènement
                        ;
                }
            }
            // Incrémente le déplacement du sprite, et le limite à l'affichage sur l'écran
            position.incr(5, 0);
            if (position.getRect().x >= (screen.getSurface().w))
            {
                position.getRect().x = 0;
            }

            // Blit le background puis le sprite sur l'écran (en double buffering)
            screen.blit(background);
            screen.blit(*spritePtr, position);

            screen.blit(*(animationUpPtr->getSprite()), positionFixeUp);
            if (0 == (nbFrame%10))
            {
                animationUpPtr->next();
            }
            screen.blit(*(animationDownPtr->getSprite()), positionFixeDown);
            if (0 == (nbFrame%10))
            {
                animationDownPtr->next();
            }
            screen.blit(*(animationRightPtr->getSprite()), positionFixeRight);
            if (0 == (nbFrame%10))
            {
                animationRightPtr->next();
            }
            screen.blit(*(animationLeftPtr->getSprite()), positionFixeLeft);
            if (0 == (nbFrame%10))
            {
                animationLeftPtr->next();
            }

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
                //std::cout << fps << std::endl;

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

