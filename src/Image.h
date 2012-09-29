#pragma once

#include <SDL/SDL.h>
#include "Surface.h"

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
             Image(const char* apFileName, const bool abHasTransparence = false);
    virtual ~Image(void);

private:
};
