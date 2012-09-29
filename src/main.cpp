#include <iostream>
#include "Animation.h"
#include "Entity.h"
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
        Sprite::Vector spriteUpVector;
        spriteUpVector.push_back (spriteUp1Ptr);
        spriteUpVector.push_back (spriteUp2Ptr);
        spriteUpVector.push_back (spriteUp3Ptr);
        spriteUpVector.push_back (spriteUp1Ptr);
        spriteUpVector.push_back (spriteUp4Ptr);
        spriteUpVector.push_back (spriteUp5Ptr);
        Animation::Ptr animationUpPtr (new Animation(spriteUpVector, 0));
        Sprite::Ptr spriteDown0Ptr  (new Sprite(planchePtr,    0, 32+64, 32, 64));
        Sprite::Ptr spriteDown3Ptr  (new Sprite(planchePtr,   32, 32+64, 32, 64));
        Sprite::Ptr spriteDown2Ptr  (new Sprite(planchePtr, 2*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown1Ptr  (new Sprite(planchePtr, 3*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown4Ptr  (new Sprite(planchePtr, 4*32, 32+64, 32, 64));
        Sprite::Ptr spriteDown5Ptr  (new Sprite(planchePtr, 5*32, 32+64, 32, 64));
        Sprite::Vector spriteDownVector;
        spriteDownVector.push_back (spriteDown1Ptr);
        spriteDownVector.push_back (spriteDown2Ptr);
        spriteDownVector.push_back (spriteDown3Ptr);
        spriteDownVector.push_back (spriteDown1Ptr);
        spriteDownVector.push_back (spriteDown4Ptr);
        spriteDownVector.push_back (spriteDown5Ptr);
        Animation::Ptr animationDownPtr (new Animation(spriteDownVector, 1));
        Sprite::Ptr spriteRight0Ptr  (new Sprite(planchePtr,    0, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight3Ptr  (new Sprite(planchePtr,   32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight2Ptr  (new Sprite(planchePtr, 2*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight1Ptr  (new Sprite(planchePtr, 3*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight4Ptr  (new Sprite(planchePtr, 4*32, 32+2*64, 32, 64));
        Sprite::Ptr spriteRight5Ptr  (new Sprite(planchePtr, 5*32, 32+2*64, 32, 64));
        Sprite::Vector spriteRightVector;
        spriteRightVector.push_back (spriteRight1Ptr);
        spriteRightVector.push_back (spriteRight2Ptr);
        spriteRightVector.push_back (spriteRight3Ptr);
        spriteRightVector.push_back (spriteRight1Ptr);
        spriteRightVector.push_back (spriteRight4Ptr);
        spriteRightVector.push_back (spriteRight5Ptr);
        Animation::Ptr animationRightPtr (new Animation(spriteRightVector, 2));
        Sprite::Ptr spriteLeft0Ptr  (new Sprite(planchePtr,    0, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft3Ptr  (new Sprite(planchePtr,   32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft2Ptr  (new Sprite(planchePtr, 2*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft1Ptr  (new Sprite(planchePtr, 3*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft4Ptr  (new Sprite(planchePtr, 4*32, 32+3*64, 32, 64));
        Sprite::Ptr spriteLeft5Ptr  (new Sprite(planchePtr, 5*32, 32+3*64, 32, 64));
        Sprite::Vector spriteLeftVector;
        spriteLeftVector.push_back (spriteLeft1Ptr);
        spriteLeftVector.push_back (spriteLeft2Ptr);
        spriteLeftVector.push_back (spriteLeft3Ptr);
        spriteLeftVector.push_back (spriteLeft1Ptr);
        spriteLeftVector.push_back (spriteLeft4Ptr);
        spriteLeftVector.push_back (spriteLeft5Ptr);
        Animation::Ptr animationLeftPtr (new Animation(spriteLeftVector, 3));
        Position    positionFixeUp(0, 100);
        Position    positionFixeDown(50, 100);
        Position    positionFixeRight(100, 100);
        Position    positionFixeLeft(150, 100);
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
        Entity::Ptr entityPtr (new Entity(orientationSprites, orientationAnimations, positionInitiale));

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
                        else if (SDLK_RIGHT == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(Entity::eOrientationRight);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_DOWN == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(Entity::eOrientationDown);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_LEFT == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(Entity::eOrientationLeft);
                            entityPtr->setSpeed(2);
                        }
                        else if (SDLK_UP == event.key.keysym.sym)
                        {
                            entityPtr->setOrientation(Entity::eOrientationUp);
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
                        // Test de position de la souris
                        entityPtr->updateMousePosition(event.motion.x, event.motion.y);

                        if (event.motion.state & SDL_BUTTON(1)) // Bouton Gauche appuyé
                        {
                            position.set (event.motion.x - spritePtr->getSurface().getSurface().w/2,
                                          event.motion.y - spritePtr->getSurface().getSurface().h/2);
                        }
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        position.set (event.motion.x - spritePtr->getSurface().getSurface().w/2,
                                      event.motion.y - spritePtr->getSurface().getSurface().h/2);
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
//            if (0 == (nbFrame%10))
//            {
//                animationUpPtr->next();
//            }
            screen.blit(*(animationDownPtr->getSprite()), positionFixeDown);
            screen.blit(*(animationRightPtr->getSprite()), positionFixeRight);
            screen.blit(*(animationLeftPtr->getSprite()), positionFixeLeft);

            if (0 == entityPtr->getSpeed())
            {
                screen.blit(*(entityPtr->getSprite()), entityPtr->getPosition());
            }
            else
            {
                // TODO SRO : déplacer cette logique dans Entity
                switch (entityPtr->getOrientation())
                {
                    case Entity::eOrientationRight:
                        entityPtr->getPosition().incr(entityPtr->getSpeed(), 0);
                        break;
                    case Entity::eOrientationDown:
                        entityPtr->getPosition().incr(0, entityPtr->getSpeed());
                        break;
                    case Entity::eOrientationLeft:
                        entityPtr->getPosition().incr(-entityPtr->getSpeed(), 0);
                        break;
                    case Entity::eOrientationUp:
                        entityPtr->getPosition().incr(0, -entityPtr->getSpeed());
                        break;
                    default:
                        ;
                }
                if (0 == (nbFrame%10))
                {
                    entityPtr->getAnimation()->next();
                }
                screen.blit(*(entityPtr->getAnimation()->getSprite()), entityPtr->getPosition());
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
                //std::cout << fps << " fps" << std::endl;

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

