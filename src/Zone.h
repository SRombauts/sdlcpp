#pragma once

/**
 * @brief Encapsulation d'une zone cliquable rectangle
 *
 * Zone rectangle (x,y) (x2,y2) définie à partir d'une position (x,y) et de dimensions (w,h),
 * avec x2=x+w-1 et y2=y+h-1.
 * Ces 4 coordonnées sont considérées comme immuables.
 *
 * Toute Zone est enregistrée auprès du ZoneManager ou auprès de sa Zone mère (en cas de hiérarchie).
*/
class Zone
{
public:
             Zone(const unsigned int aX,
                  const unsigned int aY,
                  const unsigned int aW,
                  const unsigned int aH);
    virtual ~Zone(void);

    /// Indique si les coordonnées sont sur la zone (bordures incluses)
    bool isInside           (const unsigned int aX, const unsigned int aY) const;

    /// Indique si la souris est au dessus de la zone (bordures incluses)
    bool updateMousePosition(const unsigned int aX, const unsigned int aY);

    /// Accesseurs simples
    inline unsigned int getX(void) const
    {
        return mX;
    }
    inline unsigned int getY(void) const
    {
        return mY;
    }
    inline unsigned int getX2(void) const
    {
        return mX2;
    }
    inline unsigned int getY2(void) const
    {
        return mY2;
    }
    inline bool isMouseInside(void) const
    {
        return mbIsMouseInside;
    }

private:
    unsigned int    mX;     //!< X coordonnée du côté gauche
    unsigned int    mY;     //!< Y coordonnée du haut
    unsigned int    mX2;    //!< X2=x+w coordonnée du côté droit
    unsigned int    mY2;    //!< Y2=y+h coordonnée du bas
    bool            mbIsMouseInside;    //!< Mémorise l'état "dans/hors de la zone" de la souris (pour détection de transition)
};
