#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vendor.h"
#include "IceCream.h"

namespace seneca
{

    using namespace std;

    /// <summary>
    /// Deallocates any dynamic memory used by the object and sets it to an empty state
    /// </summary>
    void Vendor::startNewOrder()
    {
        arraySize = 0;
        numOfIceCreams = 0;

        if (iceCreams != nullptr)
        {
            delete[] iceCreams;
            iceCreams = nullptr;
        }
    }

    /// <summary>
    /// Initializes the object to a default state (initializes all the attributes to some default value or empty state).
    /// </summary>
    void Vendor::openShop()
    {
        startNewOrder();
    }

    /// <summary>
    /// Creates a new IceCream object and adds it to the collection of ice cream that the customer ordered only if the collection doesn't already contain that flavour and all the parameters are valid.
    /// <param name="flavour">the address of a C-string containing the flavour of the ice cream the customer ordered. Valid Value: any string with at least one character.</param>
    /// <param name="cntScoops">an integer with the number of scoops for this ice cream. Valid Value: only the value 1, 2, and 3.</param>
    /// <param name="hasVanillaWafer">if the ice cream should be in a vanilla wafer; false if a plastic cup should be used instead.</param>
    /// <summary>
    void Vendor::addToOrder(const char *flavour, int cntScoops, bool hasVanillaWafer)
    {
        // Validate flavour ( check if no flavour passed or empty string passed )
        if (flavour == nullptr || strcmp(flavour, "") == 0)
            return;

        // validate scoops ( as only 1, 2, 3 are allowed )
        if (cntScoops < 1 || cntScoops > 3)
            return;

        // Check if the flavour is already in the order
        for (int i = 0; i < numOfIceCreams; ++i)
        {
            if (strcmp(iceCreams[i].getFlavour(), flavour) == 0)
            {
                return;
            }
        }

        // Resize the array when adding new ice cream
        IceCream *newArray = new IceCream[numOfIceCreams + 1];
        for (int i = 0; i < numOfIceCreams; ++i)
            newArray[i] = iceCreams[i];

        delete[] iceCreams;
        iceCreams = newArray;
        arraySize = numOfIceCreams + 1;

        // Add the new IceCream object to the array
        iceCreams[numOfIceCreams++] = IceCream(flavour, cntScoops, hasVanillaWafer);
    }

    /// <summary>
    /// Print to screen the receipt for the customer's order, containing the ice creams in the order, the details for each ice cream, and a breakdown of prices.
    /// <summary>
    void Vendor::displayOrderReceipt() const
    {

        // Save current formatting options
        std::ios_base::fmtflags originalFlags = std::cout.flags();
        std::streamsize originalPrecision = std::cout.precision();
        std::streamsize originalWidth = std::cout.width();
        char originalFill = std::cout.fill();

        // set precision to 2 digits
        std::cout << std::fixed << std::setprecision(2);
        std::cout.fill('.');

        std::cout << "\n*********** Customer Receipt Copy ***********\n";
        float grandTotal = 0;

        for (int i = 0; i < numOfIceCreams; ++i)
        {
            float total = 0.00;
            float flavorPrice = getFlavourPrice(iceCreams[i].getFlavour());
            float scoopPrice = flavorPrice * iceCreams[i].getScoops();

            total += scoopPrice;

            if (iceCreams[i].hasWafer())
                total += 0.5;

            cout << "#" << i + 1 << ". ";
            cout.width(37);
            cout << std::left << iceCreams[i].getFlavour() << total << endl;

            cout.width(7);
            cout.fill(' ');
            std::cout << std::right << iceCreams[i].getScoops() << " scoops @ " << flavorPrice << " each";
            cout.width(10);
            cout.fill('.');
            cout << scoopPrice << endl;

            if (iceCreams[i].hasWafer())
            {
                cout.width(11);
                cout.fill(' ');
                cout << std::right << "Wafer";
                cout.width(25);
                cout.fill('.');
                cout << std::right << getWaferPrice() << endl;
            }

            grandTotal += total;
        }

        // 2. Calculate tax
        double tax = grandTotal * 0.13;

        // 3. Calculate price with tax
        double grandTotalWithTax = grandTotal + tax;

        // 4. Show the bill using formatted output

        cout << endl
             << endl;

        cout.width(35);
        cout.fill(' ');
        cout << "Price before tax";
        cout.width(10);
        cout.fill('.');
        cout << grandTotal << endl;

        cout.width(35);
        cout.fill(' ');
        cout << "Tax";
        cout.width(10);
        cout.fill('.');
        cout << tax << endl;

        cout.width(35);
        cout.fill(' ');
        cout << "Price with tax";
        cout.width(10);
        cout.fill('.');
        cout << grandTotalWithTax << endl;

        cout.width(45);
        cout.fill('*');
        cout << "";

        // 5. Restore all config to remove side-effects
        std::cout.precision(originalPrecision);
        std::cout.width(originalWidth);
        std::cout.flags(originalFlags);
        std::cout.fill(originalFill);
        cout << endl;
    }

    /// <summary>
    /// Get the price of individual flavour.
    /// <param name="flavour">the address of a C-string containing the flavour of the ice cream the customer ordered. Valid Value: any string with at least one character.</param>
    /// </summary>
    float Vendor::getFlavourPrice(const char *flavour) const
    {
        if (strcmp(flavour, "Chocolate") == 0)
            return 1.24;
        else if (strcmp(flavour, "Tutti Frutti") == 0)
            return 1.50;
        else
            return 0.99;
    }

    /// <summary>
    /// Get the price of wafer.
    /// </summary>
    float Vendor::getWaferPrice() const
    {
        return 0.5;
    }

    /// <summary>
    /// Deallocates any dynamic memory used by the object and sets it to an empty state.
    /// </summary>
    void Vendor::closeShop()
    {
        for (int i = 0; i < numOfIceCreams; i++)
            delete[] iceCreams[i].getFlavour();

        delete[] iceCreams;
    }

} // namespace seneca
