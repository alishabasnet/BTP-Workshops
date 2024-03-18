#ifndef VENDOR_H
#define VENDOR_H

#include "IceCream.h"

namespace seneca
{

    /// <summary>
    /// Vendor class
    /// </summary>
    class Vendor
    {
    private:
        /// <summary>
        ///  Dynamic array to store ice creams
        /// </summary>
        IceCream *iceCreams;

        /// <summary>
        ///  Total no. of ice creams in the order
        /// </summary>
        int numOfIceCreams;

        /// <summary>
        ///  size of the array
        /// </summary>
        int arraySize;

    public:
        // Public functions

        /// <summary>
        /// Deallocates any dynamic memory used by the object and sets it to an empty state
        /// </summary>
        void startNewOrder();

        /// <summary>
        /// Initializes the object to a default state (initializes all the attributes to some default value or empty state).
        /// </summary>
        void openShop();

        /// <summary>
        /// Creates a new IceCream object and adds it to the collection of ice cream that the customer ordered only if the collection doesn't already contain that flavour and all the parameters are valid.
        /// <param name="flavour">the address of a C-string containing the flavour of the ice cream the customer ordered. Valid Value: any string with at least one character.</param>
        /// <param name="cntScoops">an integer with the number of scoops for this ice cream. Valid Value: only the value 1, 2, and 3.</param>
        /// <param name="hasVanillaWafer">if the ice cream should be in a vanilla wafer; false if a plastic cup should be used instead.</param>
        /// <summary>
        void addToOrder(const char *flavour, int cntScoops, bool hasVanillaWafer);

        /// <summary>
        /// Print to screen the receipt for the customer's order, containing the ice creams in the order, the details for each ice cream, and a breakdown of prices.
        /// <summary>
        void displayOrderReceipt() const;

        /// <summary>
        /// Deallocates any dynamic memory used by the object and sets it to an empty state.
        /// </summary>
        void closeShop();

    private:
        /// <summary>
        /// Get the price of individual flavour.
        /// <param name="flavour">the address of a C-string containing the flavour of the ice cream the customer ordered. Valid Value: any string with at least one character.</param>
        /// </summary>
        float getFlavourPrice(const char *flavour) const;

        /// <summary>
        /// Get the price of wafer.
        /// </summary>
        float getWaferPrice() const;
    };
}

#endif // VENDOR_H
