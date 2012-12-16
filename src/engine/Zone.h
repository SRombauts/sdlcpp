#pragma once

#include <boost/intrusive/list.hpp>

class IZoneCallbacks;

/**
 * @brief Encapsulation d'une zone rectangle cliquable de l'écran.
 *
 * Zone rectangle (x,y) (x2,y2) définie à partir d'une position (x,y) et de dimensions (w,h),
 * avec x2=x+w-1 et y2=y+h-1.
 *
 * Ces 4 coordonnées sont mises à jour à chaque fois que l'objet sous-jacent est déplacé.
 *
 * Toute Zone est enregistrée auprès du ZoneManager ou auprès de sa Zone mère (en cas de hiérarchie).
 *
 * @author 2012/09/29 SRombauts
*/
class Zone : public boost::intrusive::list_base_hook<> // Base hook with default tag, raw pointers and safe_link mode
{
    friend class ZoneManager;

public:
    /// Liste intrusive doublement chaînée de #Zone (et non pas de pointeurs de #Zone)
    /// => utilisée parce que les Zones sont des objets membres (composition)
    ///    et qu'on veut donc simplement en faire une liste "light"
    /// TODO SRO : sujet à mettre au propre à tête reposée
    typedef boost::intrusive::list<Zone> List;

public:
             Zone(IZoneCallbacks&    aZoneCallbacks,
                  const unsigned int aX,
                  const unsigned int aY,
                  const unsigned int aW,
                  const unsigned int aH);
    virtual ~Zone(void);

    /// Met à jour les coordonnées (x,y) et recalcule (x2,y2)
    void set(const unsigned int aX, const unsigned int aY);

    /// Indique si les coordonnées sont sur la zone (bordures incluses)
    bool isOver             (const unsigned int aX, const unsigned int aY) const;

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
        return mbIsMouseOver;
    }

private:
    // Notifie la #Zone
    void onMouseMotion(const unsigned int aX, const unsigned int aY, const bool abIsDown, bool& abAlreadyConsumed);
    void onMouseEvent (const unsigned int aX, const unsigned int aY, const bool abIsDown, bool& abAlreadyConsumed);

private:
    IZoneCallbacks& mZoneCallbacks; //!< Instance à notifier des changements d'état
    unsigned int    mX;     //!< X coordonnée du côté gauche
    unsigned int    mY;     //!< Y coordonnée du haut
    unsigned int    mW;     //!< W largeur de la zone
    unsigned int    mH;     //!< H hauteur de la zone
    unsigned int    mX2;    //!< X2=x+w-1 coordonnée du côté droit
    unsigned int    mY2;    //!< Y2=y+h-1 coordonnée du bas
    bool            mbIsMouseOver;  //!< Mémorise l'état "dans/hors de la zone" de la souris (pour détection de transition)
    bool            mbIsClicked;    //!< Mémorise le fait que la zone a été cliquée
    bool            mbIsDraged;     //!< Mémorise le fait que la zone a été draguée
    bool            mbOnOverCalled; //!< Mémorise le fait que la callback onOver a été appelée
};
