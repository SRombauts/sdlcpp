#include "Image.h"
#include "Screen.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include <cassert>

/// Constructeur RAII (exception en cas d'erreur : l'objet est toujours valide)
Image::Image(const char* apFileName,
             const unsigned char aR /* = 255 */,
             const unsigned char aG /* = 255 */,
             const unsigned char aB /* = 255 */,
             const unsigned char aAlpha /* = SDL_ALPHA_OPAQUE */)
{
    assert(apFileName && "Image ctor need a filename");
    SDL_Surface* pSurfaceUnoptimized = nullptr; // Surface tampon pour charger l'image non optimisé

    std::cout << "image: SDL_LoadBMP(" << apFileName << ")" << std::endl;

    // Chargement de l'image
    pSurfaceUnoptimized = SDL_LoadBMP(apFileName);
    // Si le chargement s'est bien passé
    if (nullptr != pSurfaceUnoptimized)
    {
        // TODO SRombauts : à revoir avec le chargement des PNG avec transparence
        if (   (0 != aR)
            || (0 != aG)
            || (0 != aB) )
        {
            // Définition de la couleur de transparence le cas échéant
            Uint32 colorkey = SDL_MapRGB(pSurfaceUnoptimized->format, aR, aG, aB);
            int Ret = SDL_SetColorKey(pSurfaceUnoptimized, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey);
            if (-1 == Ret)
            {
                std::cout << "image: SDL_SetColorKey error: " << SDL_GetError() << std::endl;
            }
            else
                std::cout << "image: SDL_SetColorKey ok" << std::endl;
        }

        // TODO SRombauts : à revoir avec le chargement des PNG avec transparence
        if (SDL_ALPHA_OPAQUE != aAlpha)
        {
            // Définition d'un éventuel canal alpha
            int Ret = SDL_SetAlpha(pSurfaceUnoptimized, SDL_RLEACCEL | SDL_SRCALPHA, aAlpha); // SDL_ALPHA_TRANSPARENT = 0 => OPTIMAL = 128 => SDL_ALPHA_OPAQUE = 255
            if (-1 == Ret)
            {
                std::cout << "image: SDL_SetAlpha error: " << SDL_GetError() << std::endl;
            }
            else
                std::cout << "image: SDL_SetAlpha ok" << std::endl;
        }

        if (SDL_ALPHA_OPAQUE != aAlpha)
        {
            // Création de l'image optimisée (y compris concernant la transparence ET le canal alpha)
            mpSurface = SDL_DisplayFormatAlpha(pSurfaceUnoptimized);
        }
        else
        {
            // Création de l'image optimisée (y compris concernant sans canal alpha, mais avec l'éventuel transparence)
            // TODO voir si cela apporte qqch de ne pas utiliser SDL_DisplayFormatAlpha
            mpSurface = SDL_DisplayFormat(pSurfaceUnoptimized);
        }
        if (nullptr != mpSurface)
        {
            std::cout << "image: SDL_DisplayFormat/SDL_DisplayFormatAlpha ok" << std::endl;
            // Libération de l'image non optimisée
            SDL_FreeSurface(pSurfaceUnoptimized);
        }
        else
        {
           std::ostringstream streamErr;
           streamErr << "Image: Optimize error: " << SDL_GetError() << std::endl;
           throw std::runtime_error(streamErr.str());
        }
/* TODO SRombauts : tests en cours
abort();
int i = 0;
int j = 1/i;
std::ostringstream streamErr;
streamErr << "Image: Optimize error: " << SDL_GetError() << std::endl;
BOOST_THROW_EXCEPTION(std::runtime_error(streamErr.str()));
*/
    }
    else
    {
        std::ostringstream streamErr;
        streamErr << "Image: Load error: " << SDL_GetError() << std::endl;
        throw std::runtime_error(streamErr.str());
    }
}

/// Destructeur : libération des ressources
Image::~Image(void)
{
    // Tout est fait dans le destructeur Surface::~Surface() de la classe mère
}
