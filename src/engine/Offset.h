#pragma once

/**
 * @brief Encapsulation d'un offset (x,y) générique
 *
 * Sert à décrire la différence entre une #Position (x,y) absolue d'un objet et :
 * - les coordonnées graphiques (#Coord) relatives à la surface sous jacente
 * - la position d'une #Zone dans le référentiel de la fenêtre (souris)
 *
 * @see Voir aussi #Size
 *
 * @author 2012/09/30 SRombauts
*/
class Offset
{
public:
     Offset(const int aX = 0, const int aY = 0);
    ~Offset(void); // non virtuel car non destiné à être dérivé

    /// Met à jour les coordonnées (x,y)
    void set(const int aX, const int aY);
    void incr(const int aIncrX, const int aIncrY);

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
