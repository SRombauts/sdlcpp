#include <iostream>
#include "engine/Animation.h"
#include "engine/Coord.h"
#include "engine/UnitPlayer.h"
#include "engine/Image.h"
#include "engine/Screen.h"
#include "engine/Size.h"
#include "engine/Sprite.h"
#include "engine/UI.h"
#include "engine/ZoneManager.h"

#include <boost/make_shared.hpp>

#include "backtrace.h"
#include "signal_handler.h"

// Les paramètres de notre écran
const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 480;


void my_terminate_handler (void);

std::terminate_handler _default_terminate_handler = NULL;
void my_terminate_handler (void)
{
    print_backtrace();
    if (NULL != _default_terminate_handler)
    {
        _default_terminate_handler();
    }
}

/**
 * @author 2012/09/26 SRombauts
*/
int main(int argc, char* argv[])
{
    bool        bRunning = true;
    int         res;
    SDL_Event   event;

    _default_terminate_handler = std::set_terminate(my_terminate_handler);

    install_signal_handler();

    for (int arg = 0; arg < argc; arg++)
    {
        std::cout << argv[arg] << std::endl;
    }

    std::cout << std::endl << "*** SDL_Init... ***" << std::endl;
    res = SDL_Init(SDL_INIT_VIDEO);
    if (-1 != res)
    {
        Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");

        Image       background  ("res/background.bmp");
        Image::Ptr  planchePtr  = boost::make_shared<Image>("res/animation.bmp", 0, 0xFF, 0xFF);
        Image::Ptr  imageUIPtr  = boost::make_shared<Image>("res/tower.bmp", 0, 0xFF, 0xFF);
        Sprite::Ptr spriteUIPtr = boost::make_shared<Sprite>(imageUIPtr, 0, 0, 96, 96);
        Image::Ptr  towersPtr   = boost::make_shared<Image>("res/tower-sprites.bmp", 0, 0xFF, 0xFF, SDL_ALPHA_128);
        Sprite::Ptr towerPtr      = boost::make_shared<Sprite>(towersPtr, 12, 12, 32, 32);
        Sprite::Ptr spriteUp0Ptr  = boost::make_shared<Sprite>(planchePtr, 0*32, 32, 32, 64);
        Sprite::Ptr spriteUp3Ptr  = boost::make_shared<Sprite>(planchePtr, 1*32, 32, 32, 64);
        Sprite::Ptr spriteUp2Ptr  = boost::make_shared<Sprite>(planchePtr, 2*32, 32, 32, 64);
        Sprite::Ptr spriteUp1Ptr  = boost::make_shared<Sprite>(planchePtr, 3*32, 32, 32, 64);
        Sprite::Ptr spriteUp4Ptr  = boost::make_shared<Sprite>(planchePtr, 4*32, 32, 32, 64);
        Sprite::Ptr spriteUp5Ptr  = boost::make_shared<Sprite>(planchePtr, 5*32, 32, 32, 64);
        Sprite::Vector spriteUpVector;
        spriteUpVector.push_back (spriteUp1Ptr);
        spriteUpVector.push_back (spriteUp2Ptr);
        spriteUpVector.push_back (spriteUp3Ptr);
        spriteUpVector.push_back (spriteUp1Ptr);
        spriteUpVector.push_back (spriteUp4Ptr);
        spriteUpVector.push_back (spriteUp5Ptr);
        Animation::Ptr animationUpPtr= boost::make_shared<Animation>(spriteUpVector, 0);
        Sprite::Ptr spriteDown0Ptr  = boost::make_shared<Sprite>(planchePtr, 0*32, 32+64, 32, 64);
        Sprite::Ptr spriteDown3Ptr  = boost::make_shared<Sprite>(planchePtr, 1*32, 32+64, 32, 64);
        Sprite::Ptr spriteDown2Ptr  = boost::make_shared<Sprite>(planchePtr, 2*32, 32+64, 32, 64);
        Sprite::Ptr spriteDown1Ptr  = boost::make_shared<Sprite>(planchePtr, 3*32, 32+64, 32, 64);
        Sprite::Ptr spriteDown4Ptr  = boost::make_shared<Sprite>(planchePtr, 4*32, 32+64, 32, 64);
        Sprite::Ptr spriteDown5Ptr  = boost::make_shared<Sprite>(planchePtr, 5*32, 32+64, 32, 64);
        Sprite::Vector spriteDownVector;
        spriteDownVector.push_back (spriteDown1Ptr);
        spriteDownVector.push_back (spriteDown2Ptr);
        spriteDownVector.push_back (spriteDown3Ptr);
        spriteDownVector.push_back (spriteDown1Ptr);
        spriteDownVector.push_back (spriteDown4Ptr);
        spriteDownVector.push_back (spriteDown5Ptr);
        Animation::Ptr animationDownPtr= boost::make_shared<Animation>(spriteDownVector, 1);
        Sprite::Ptr spriteRight0Ptr  = boost::make_shared<Sprite>(planchePtr, 0*32, 32+2*64, 32, 64);
        Sprite::Ptr spriteRight3Ptr  = boost::make_shared<Sprite>(planchePtr, 1*32, 32+2*64, 32, 64);
        Sprite::Ptr spriteRight2Ptr  = boost::make_shared<Sprite>(planchePtr, 2*32, 32+2*64, 32, 64);
        Sprite::Ptr spriteRight1Ptr  = boost::make_shared<Sprite>(planchePtr, 3*32, 32+2*64, 32, 64);
        Sprite::Ptr spriteRight4Ptr  = boost::make_shared<Sprite>(planchePtr, 4*32, 32+2*64, 32, 64);
        Sprite::Ptr spriteRight5Ptr  = boost::make_shared<Sprite>(planchePtr, 5*32, 32+2*64, 32, 64);
        Sprite::Vector spriteRightVector;
        spriteRightVector.push_back (spriteRight1Ptr);
        spriteRightVector.push_back (spriteRight2Ptr);
        spriteRightVector.push_back (spriteRight3Ptr);
        spriteRightVector.push_back (spriteRight1Ptr);
        spriteRightVector.push_back (spriteRight4Ptr);
        spriteRightVector.push_back (spriteRight5Ptr);
        Animation::Ptr animationRightPtr = boost::make_shared<Animation>(spriteRightVector, 2);
        Sprite::Ptr spriteLeft0Ptr  = boost::make_shared<Sprite>(planchePtr, 0*32, 32+3*64, 32, 64);
        Sprite::Ptr spriteLeft3Ptr  = boost::make_shared<Sprite>(planchePtr, 1*32, 32+3*64, 32, 64);
        Sprite::Ptr spriteLeft2Ptr  = boost::make_shared<Sprite>(planchePtr, 2*32, 32+3*64, 32, 64);
        Sprite::Ptr spriteLeft1Ptr  = boost::make_shared<Sprite>(planchePtr, 3*32, 32+3*64, 32, 64);
        Sprite::Ptr spriteLeft4Ptr  = boost::make_shared<Sprite>(planchePtr, 4*32, 32+3*64, 32, 64);
        Sprite::Ptr spriteLeft5Ptr  = boost::make_shared<Sprite>(planchePtr, 5*32, 32+3*64, 32, 64);
        Sprite::Vector spriteLeftVector;
        spriteLeftVector.push_back (spriteLeft1Ptr);
        spriteLeftVector.push_back (spriteLeft2Ptr);
        spriteLeftVector.push_back (spriteLeft3Ptr);
        spriteLeftVector.push_back (spriteLeft1Ptr);
        spriteLeftVector.push_back (spriteLeft4Ptr);
        spriteLeftVector.push_back (spriteLeft5Ptr);
        Animation::Ptr animationLeftPtr= boost::make_shared<Animation>(spriteLeftVector, 3);
        Sprite::Vector  orientationSprites;
        orientationSprites.push_back(spriteRight0Ptr);
        orientationSprites.push_back(spriteDown0Ptr);
        orientationSprites.push_back(spriteLeft0Ptr);
        orientationSprites.push_back(spriteUp0Ptr);
        Animation::Vector   orientationAnimations;
        orientationAnimations.push_back(animationRightPtr);
        orientationAnimations.push_back(animationDownPtr);
        orientationAnimations.push_back(animationLeftPtr);
        orientationAnimations.push_back(animationUpPtr);
        Position    positionInitiale(300, 200);
        Offset      offsetInitial(0, 0);
        Size        sizeUnitPlayer(32, 64);
        UnitPlayer::Ptr entityPtr= boost::make_shared<UnitPlayer>(orientationSprites, orientationAnimations, positionInitiale, offsetInitial, sizeUnitPlayer);

        Coord       coordUI(800-104, 8);
        Size        sizeUI(96, 96);
        UI::Ptr     uiPtr    = boost::make_shared<UI>(coordUI, sizeUI, spriteUIPtr, spriteUIPtr, spriteUIPtr, spriteUIPtr, towerPtr);

        /// TODO SRO : sujet à mettre au propre à tête reposée ; le remove() !
        ZoneManager zoneManager;
        zoneManager.getList().push_back(entityPtr->getZone());
        zoneManager.getList().push_back(uiPtr->getZone());

        Uint32 firstTick = SDL_GetTicks();
        Uint32 lastTick = firstTick;
        Uint32 fpsTick  = firstTick;
        Uint32 animTick = firstTick;
        Uint32 nbFrame  = 0;
        Uint32 fps = 0;
        while (bRunning)
        {
            Uint32 currentTick  = SDL_GetTicks();

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
                        else if (SDLK_RIGHT == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(UnitPlayer::eOrientationRight);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_DOWN == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(UnitPlayer::eOrientationDown);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_LEFT == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(UnitPlayer::eOrientationLeft);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_UP == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(UnitPlayer::eOrientationUp);
                            entityPtr->setSpeed(2);
                        }
                        break;
                    case SDL_KEYUP:
                        // Si une touche est relâchée
                        if (SDLK_RIGHT == event.key.keysym.sym)
                        {
                            entityPtr->setSpeed(0);
                        }
                        else if (SDLK_DOWN == event.key.keysym.sym)
                        {
                            entityPtr->setSpeed(0);
                        }
                        else if (SDLK_LEFT == event.key.keysym.sym)
                        {
                            entityPtr->setSpeed(0);
                        }
                        else if (SDLK_UP == event.key.keysym.sym)
                        {
                            entityPtr->setSpeed(0);
                        }
                        break;
                    case SDL_MOUSEMOTION:
                        // Test de position de la souris vis à vis de l'arborescence des listes
                        zoneManager.onMouseMotion(event.motion.x, event.motion.y, (event.motion.state & SDL_BUTTON(1)));
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        if (SDL_BUTTON_LEFT == event.button.button)
                        {
                            // Test de position de la souris vis à vis de l'arborescence des listes
                            zoneManager.onMouseEvent(event.button.x, event.button.y, true);
                        }
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (SDL_BUTTON_LEFT == event.button.button)
                        {
                            // Test de position de la souris vis à vis de l'arborescence des listes
                            zoneManager.onMouseEvent(event.button.x, event.button.y, false);
                        }
                        break;
                    default:
                        // Autre évènement
                        ;
                }
            }

            // déplace l'entité
            entityPtr->move();

            // Blit d'abord le background sur l'écran
            screen.blit(background);

            // Blit l'UI
            uiPtr->show(screen);

            if (0 != entityPtr->getSpeed())
            {
                // Se base sur le temps qui passe pour animer l'entité
                // TODO SRO : déplacer cette logique dans UnitPlayer
                if (100 < (currentTick-animTick))
                {
                    animTick = currentTick;
                    entityPtr->getAnimation()->next();
                }
            }

            // Blit ensuite l'entité (en statique, une image de l'animation)
            entityPtr->show(screen);

            // Mise à jour de l'écran (utilise le double buffering)
            screen.flip();

            // Calcul du framerate
            nbFrame++;
            // Met à jour l'indicateur de FPS seulement une fois par seconde
            Uint32 deltaFpsTick = (currentTick - fpsTick);
            if (1000 < deltaFpsTick)
            {
                fps = (nbFrame*1000)/deltaFpsTick;
                //std::cout << fps << " fps" << std::endl;

                fpsTick = currentTick;
                nbFrame = 0;
            }

            // Lissage du framerate vers 30 fps (33ms par frame)
            Uint32 deltaTick = (currentTick - lastTick);
            if (deltaTick < 60)
            {
                SDL_Delay(60 - deltaTick);
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
    std::cout << "*** SDL_Quit done ***" << std::endl;

    return EXIT_SUCCESS;
}

