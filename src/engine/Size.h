#pragma once

/**
 * @brief Encapsulation d'une taille (w,h) générique
 *
 * Ces dimensions (w,h) sont considérées comme immuables.
 *
 * @see Voir aussi #Size et #Zone
 *
 * @author 2012/10/05 SRombauts
*/
class Size
{
public:
     Size(const int aW = 0, const int aH = 0);
    ~Size(void); // non virtuel car non destiné à être dérivé

    /// Accesseurs simples
    inline int getW(void) const
    {
        return mW;
    }
    inline int getH(void) const
    {
        return mH;
    }

private:
    int mW; //!< Largeur
    int mH; //!< Hauteur
};
