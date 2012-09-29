#pragma once

/**
 * @brief Encapsulation d'une zone cliquable rectangle x,y,x2,y2
 *
 * Ces 4 coordonnées sont considérées comme immuables.
 * Toute Zone est enregistrée auprès du ZoneManager, ou auprès d'une Zone mère.
*/
class Zone
{
public:
             Zone(const unsigned int aX,
                  const unsigned int aY,
                  const unsigned int aW,
                  const unsigned int aH);
    virtual ~Zone(void);

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

private:
    unsigned int    mX;     //!< X coordonnée du côté gauche
    unsigned int    mY;     //!< Y coordonnée du haut
    unsigned int    mX2;    //!< X2=x+w coordonnée du côté droit
    unsigned int    mY2;    //!< Y2=y+h coordonnée du bas
};
