#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'un offset (x,y) générique
 *
 * Sert à décrire la différence entre une position (x,y) absolue d'un objet et :
 * - les coordonnées graphiques (#Coord) relatives à la surface sous jacente
 * - la position d'une #Zone dans le référentiel de la fenêtre (souris)
 *
 * @author 2012/09/30 SRombauts
*/
class Offset
{
public:
     Offset(const int aX = 0, const int aY = 0);
    ~Offset(void); // non virtuel car non destiné à être dérivée

    /// Met à jour les coordonnées (x,y)
    void set(const int aX = 0, const int aY = 0);
    void incr(const int aIncrX = 0, const int aIncrY = 0);

    /// Accesseurs simples
    inline int getX(void) const
    {
        return mX;
    }
    inline int getY(void) const
    {
        return mY;
    }

private:
    int mX; //!< Abscisse de la position
    int mY; //!< Ordonnée de la position
};
