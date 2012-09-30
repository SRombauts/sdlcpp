#pragma once

#include <SDL/SDL.h>

/**
 * @brief Encapsulation d'une position (x,y) générique
 *
 * Sert à décrire la position (x,y) absolue d'un objet. Elle est à l'origine :
 * - des coordonnées graphiques (#Coord) relatives à la surface sous jacente
 * - de la position d'une #Zone dans le référentiel de la fenêtre (souris)
 *
 * @author 2012/09/30 SRombauts
*/
class Position
{
public:
     Position(const int aX = 0, const int aY = 0);
    ~Position(void); // non virtuel car non destiné à être dérivée

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
