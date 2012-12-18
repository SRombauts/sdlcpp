#include <iostream>
#include "engine/Animation.h"
#include "engine/Coord.h"
#include "engine/UnitTower.h"
#include "engine/Image.h"
#include "engine/Screen.h"
#include "engine/Size.h"
#include "engine/Sprite.h"
#include "engine/UI.h"
#include "engine/ZoneManager.h"

#include <boost/make_shared.hpp>

#ifdef __GNUC__
    #include "backtrace.h"
    #include "signal_handler.h"
#endif

// Les paramètres de notre écran
const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 480;


void my_terminate_handler (void);

std::terminate_handler _default_terminate_handler = NULL;
void my_terminate_handler (void)
{
#ifdef __GNUC__
    print_backtrace();
#endif
    if (NULL != _default_terminate_handler)
    {
        _default_terminate_handler();
    }
}


// En Release le link Système se fait en /SUBSYSTEM:WINDOWS avec SDL.lib et SDLmain.lib qui implémente la redirection de WinMain() vers main()
// En Debug ce undef défait cette redirection pour permettre la compilation en mode /SUBSYSTEM:CONSOLE activant la sortie de traces
#if defined(_WIN32) && defined(_DEBUG)
#undef main
#endif


/**
 * @author 2012/09/26 SRombauts
*/
int main(int argc, char* argv[])
{
    bool        bRunning = true;
    bool        bInMenu  = true;
    int         res;
    SDL_Event   event;

    _default_terminate_handler = std::set_terminate(my_terminate_handler);

#ifdef __GNUC__
    install_signal_handler();
#endif

    for (int arg = 0; arg < argc; arg++)
    {
        std::cout << argv[arg] << std::endl;
    }

    std::cout << std::endl << "*** SDL_Init... ***" << std::endl;
    res = SDL_Init(SDL_INIT_VIDEO);
    if (-1 != res)
    {
        ZoneManager zoneManager;

        Screen screen(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World");

        Image       background  ("res/background.bmp");

        Image::Ptr  towersPtr       = boost::make_shared<Image>("res/tower-sprites.bmp", 0, 0xFF, 0xFF);
        Sprite::Ptr towerRightPtr   = boost::make_shared<Sprite>(towersPtr, 8, 8, 48, 48);
        Sprite::Ptr towerDownPtr    = boost::make_shared<Sprite>(towersPtr, 8, 8, 48, 48);
        Sprite::Ptr towerLeftPtr    = boost::make_shared<Sprite>(towersPtr, 12+64, 12, 32, 32);
        Sprite::Ptr towerUpPtr      = boost::make_shared<Sprite>(towersPtr, 12, 12, 32, 32);
        Sprite::Vector orientationTower;
        orientationTower.push_back(towerRightPtr);
        orientationTower.push_back(towerDownPtr);
        orientationTower.push_back(towerLeftPtr);
        orientationTower.push_back(towerUpPtr);
        UnitTower::Vector   towerVector;
        for (int i = 0; i < 10; i++)
        {
            Position    positionTower(10 + i*48, 100);
            Offset      offsetTower;
            Size        sizeTower(48, 48);
            UnitTower::Ptr      towerPtr = boost::make_shared<UnitTower>(orientationTower, positionTower, offsetTower, sizeTower);
            towerVector.push_back(towerPtr);
            zoneManager.getTowerList().push_back(towerPtr->getZone());
        }

        Image::Ptr  imageUIPtr      = boost::make_shared<Image>("res/tower.bmp", 0, 0xFF, 0xFF);
        Sprite::Ptr spriteUIPtr     = boost::make_shared<Sprite>(imageUIPtr, 0, 0, 96, 96);
        Image::Ptr  towersTranspPtr = boost::make_shared<Image>("res/tower-sprites.bmp", 0, 0xFF, 0xFF, SDL_ALPHA_128);
        Sprite::Ptr towerTranspPtr  = boost::make_shared<Sprite>(towersTranspPtr, 8, 8, 48, 48);
        Coord       coordUI(800-104, 8);
        Size        sizeUI(96, 96);
        UI::Ptr     uiPtr    = boost::make_shared<UI>(coordUI, sizeUI, spriteUIPtr, spriteUIPtr, spriteUIPtr, spriteUIPtr, towerDownPtr);
        zoneManager.getUiList().push_back(uiPtr->getZone());

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
                            // TODO SRO : gérer le menu dans une classe dédiée
                            if (bInMenu)
                            {
                                std::cout << "Menu out" << std::endl;
                                bInMenu = false;
                            }
                            else
                            {
                                std::cout << "Menu in" << std::endl;
                                bInMenu = true;
                            }
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

            if (false == bInMenu)
            {
                // TODO SRO déplacement de toutes les unités mobiles
                //UnitList.move();
            }

            // Blit d'abord le background sur l'écran
            screen.blit(background);

            // Blit l'UI
            uiPtr->show(screen);

            // Blit les tourelles
            UnitTower::Vector::iterator iTower;
            for (iTower  = towerVector.begin();
                 iTower != towerVector.end();
                 iTower++)
            {
                (*iTower)->show(screen);
            }

            if (false == bInMenu)
            {
			    // TODO SRO animation de toutes les unités
			    /*
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
			    */
            }

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
            lastTick = currentTick;
        }

        /// TODO SRO : sujet à mettre au propre à tête reposée ; le remove() automatique ?!
        /*
        zoneManager.getUiList().remove(uiPtr->getZone());
        UnitTower::Vector::iterator iTower;
        for (iTower  = towerVector.begin();
             iTower != towerVector.end();
             iTower++)
        {
            zoneManager.getUiList().remove((*iTower)->getZone());
        }
        */
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

