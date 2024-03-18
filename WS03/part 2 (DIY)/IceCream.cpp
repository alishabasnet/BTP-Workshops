#include <iostream>
#include <cstring>
#include "IceCream.h"

namespace seneca
{
    /// <summary>
    /// default constructor
    /// </summary>
    IceCream::IceCream() {}

    /// <summary>
    /// constructor with values initialization
    /// </summary>
    IceCream::IceCream(const char *flavor, int scoops, bool vanillaWafer)
    {
        cntScoops = scoops;
        hasVanillaWafer = vanillaWafer;
        flavour = new char[strlen(flavor) + 1];
    }

    /// <summary>
    /// destructor
    /// </summary>
    IceCream::~IceCream()
    {
        delete[] flavour;
    }

    /// <summary>
    /// get the flavour
    /// </summary>
    const char *IceCream::getFlavour() const
    {
        return flavour;
    }

    /// <summary>
    /// get total soops
    /// </summary>
    int IceCream::getScoops() const
    {
        return cntScoops;
    }

    /// <summary>
    /// return boolean indicating if it has wafer not not
    /// </summary>
    bool IceCream::hasWafer() const
    {
        return hasVanillaWafer;
    }

} // namespace seneca