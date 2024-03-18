#ifndef ICECREAM_H
#define ICECREAM_H

namespace seneca
{

    /// <summary>
    /// Ice cream class
    /// </summary>
    class IceCream
    {
    private:
        /// <summary>
        /// the address of a C-string containing the flavour of the ice cream the customer ordered. Valid Value: any string with at least one character
        /// </summary>
        char *flavour;

        /// <summary>
        /// an integer with the number of scoops for this ice cream. Valid Value: only the value 1, 2, and 3.
        /// </summary>
        int cntScoops;

        /// <summary>
        /// if the ice cream should be in a vanilla wafer; false if a plastic cup should be used instead
        /// </summary>
        bool hasVanillaWafer;

    public:
        /// <summary>
        /// default constructor
        /// </summary>
        IceCream();

        /// <summary>
        /// constructor with values initialization
        /// </summary>
        IceCream(const char *flavor, int scoops, bool vanillaWafer);


         /// <summary>
        /// destructor
        /// </summary>
        ~IceCream();


        /// <summary>
        /// get the flavour
        /// </summary>
        const char *getFlavour() const;

        /// <summary>
        /// get total soops
        /// </summary>
        int getScoops() const;

        /// <summary>
        /// return boolean indicating if it has wafer not not
        /// </summary>
        bool hasWafer() const;
    };
}

#endif // ICECREAM_H
