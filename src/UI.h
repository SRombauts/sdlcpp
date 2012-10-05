#pragma once

#include <SDL/SDL.h>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Coord.h"
#include "Drag.h"
#include "Sprite.h"
#include "Zone.h"
#include "ZoneCallbacks.h"

class Screen;
class Size;

/**
 * @brief Encapsulation d'un élément d'UI (User Interface)
 *
 * @author 2012/10/02 SRombauts
*/
class UI : public IZoneCallbacks
{
public:
    /// Etat courant de l'élément d'UI
    enum State
    {
        eStateDefault   = 0,
        eStateDown      = 1,
        eStateFocus     = 2,
        eStateDisabled  = 3
    };

public:
     UI(const Coord&        aCoord,
        const Size&         aSize,
        const Sprite::Ptr&  aSpriteDefaultPtr,
        const Sprite::Ptr&  aSpriteDownPtr,
        const Sprite::Ptr&  aSpriteFocusPtr,
        const Sprite::Ptr&  aSpriteDisabledPtr,
        const Sprite::Ptr&  aSpriteDragPtr);
    virtual ~UI(void);

    /// Affichage sur l'écran
    void show(Screen& aScreen);

    /// Accesseurs simples
    inline       Sprite::Ptr& getSprite(void)
    {
        return mSprites[mState];
    }
    inline const Sprite::Ptr& getSprite(void) const
    {
        return mSprites[mState];
    }
    inline       Coord& getCoord(void)
    {
        return mCoord;
    }
    inline const Coord& getCoord(void) const
    {
        return mCoord;
    }
    inline       Zone& getZone(void)
    {
        return mZone;
    }
    inline const Zone& getZone(void) const
    {
        return mZone;
    }
    inline void setState(const State aState)
    {
        mState = aState;
    }
    inline State getState(void) const
    {
        return mState;
    }

    typedef boost::shared_ptr<UI>    Ptr;
    typedef std::vector<UI::Ptr>     Vector;

private:
    // Méthodes dérivées de IZoneCallbacks
    virtual void onOver(bool& abAlreadyConsumed);
    virtual void onOut (bool& abAlreadyConsumed);
    virtual void onDrag(const unsigned int aX, const unsigned int aY, bool& abAlreadyConsumed);
    virtual void onDrop(bool& abAlreadyConsumed);
    virtual void onClic(bool& abAlreadyConsumed);

private:
    Sprite::Vector  mSprites;       //!< Liste des Sprite de l'élément d'UI (selon son état courant ci-dessous)
    Drag            mDrag;          //!< Sprite de Drag and Drop de l'élément d'UI
    Coord           mCoord;         //!< Coordonnées de l'UI dans sa surface parent
    Zone            mZone;          //!< Zone cliquable à l'écran
    State           mState;         //!< Etat courant de l'élément d'UI
};
