#pragma once

#include <SDL/SDL.h>
#include "Surface.h"

/**
 * @brief Encapsulation de la fenêtre principale de l'application
 *
 * RAII ; exception dans le constructeur en cas d'erreur : l'objet est toujours valide)
 *
 * @author 2012/09/21 SRombauts
*/
class Screen : public Surface
{
public:
            Screen(const int aWidth, const int aHeight, const char* apTitle);
   virtual ~Screen(void);

    /// Mise à jour de l'écran
    bool flip(void);

private:
};
