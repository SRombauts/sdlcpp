#pragma once

#include "Zone.h"

/**
 * @brief Gestion de la liste des #Zone racines.
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
    inline       Zone::List&  getList(void)
    {
        return mZoneList;
    }
    inline const Zone::List&  getList(void) const
    {
        return mZoneList;
    }

private:
    Zone::List  mZoneList;  //!< Liste des zones racines
};
