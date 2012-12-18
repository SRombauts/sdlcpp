#pragma once

#include "Zone.h"

/**
 * @brief Gestion des listes de #Zone.
 *
 * @author 2012/10/01 SRombauts
*/
class ZoneManager
{
public:
    ZoneManager (void);
    ~ZoneManager(void); // Destructeur non virtuel car classe non dérivée

public:
    void onMouseMotion(const unsigned int aX, const unsigned int aY, const bool abIsDown);
    void onMouseEvent (const unsigned int aX, const unsigned int aY, const bool abIsDown);

    /// Accesseurs simples
    inline       Zone::List&  getMenuList(void)
    {
        return mMenuList;
    }
    inline const Zone::List&  getMenuList(void) const
    {
        return mMenuList;
    }

    inline       Zone::List&  getUiList(void)
    {
        return mUiList;
    }
    inline const Zone::List&  getUiList(void) const
    {
        return mUiList;
    }

    inline       Zone::List&  getTowerList(void)
    {
        return mTowerList;
    }
    inline const Zone::List&  getTowerList(void) const
    {
        return mTowerList;
    }

private:
    // Listes de Zones dans par priorité décroissante
    Zone::List  mMenuList;  //!< Liste des zones des écrans de menu/sous-menu
    Zone::List  mUiList;    //!< Liste des zones de l'UI
    Zone::List  mTowerList; //!< Liste des zones des tourelles
};
