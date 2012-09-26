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
             Image(const char* apFileName, const bool abHasTransparence = false);
    virtual ~Image(void);

private:
};
