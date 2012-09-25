#pragma once

#include <SDL/SDL.h>
#include "Surface.h"

/**
 * @brief Encapsulation d'une image
 *
 * RAII ; exception dans le constructeur en cas d'erreur : l'objet est toujours valide)
*/
class Image : public Surface
{
public:
             Image(const char* apFileName, const bool abHasTransparence = false, const Sint16 aX = 0, const Sint16 aY = 0);
    virtual ~Image(void);

private:
};
