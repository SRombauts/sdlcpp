#pragma once

#include <SDL/SDL.h>
#include "Surface.h"

#define SDL_ALPHA_128   128

/**
 * @brief Encapsulation d'une image
 *
 * RAII ; exception dans le constructeur en cas d'erreur : l'objet est toujours valide)
 *
 * @author 2012/09/21 SRombauts
*/
class Image : public Surface
{
public:
             Image(const char* apFileName,
                   const unsigned char aR = 255,
                   const unsigned char aG = 255,
                   const unsigned char aB = 255,
                   const unsigned char aAlpha = SDL_ALPHA_OPAQUE);
    virtual ~Image(void);

private:
};
