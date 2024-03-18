#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include "guitarString.h"
#include <iostream>

namespace seneca
{

    /// <summary>
    /// Represents a Guitar class that manages a collection of guitar strings.
    /// </summary>
    class Guitar
    {
        ///< The model of the guitar.
        char m_model[65];
        ///< Pointer to an array of GuitarString objects.
        GuitarString *m_strings;
        ///< The number of GuitarString objects in the array.
        int m_cntStrings;

    public:
        /// <summary>
        /// Default constructor that initializes a Guitar object with the default model "Stratocaster".
        /// </summary>
        Guitar();

        /// <summary>
        /// Constructs a Guitar object with the given model.
        /// </summary>
        /// <param name="model">The model of the guitar.</param>
        Guitar(const char *model);

        /// <summary>
        /// Constructs a Guitar object with the given strings, count of strings, and model.
        /// </summary>
        /// <param name="strings">An array of GuitarString objects.</param>
        /// <param name="cntStrings">The count of strings.</param>
        /// <param name="model">The model of the guitar.</param>
        Guitar(const GuitarString *strings, int cntStrings, const char *model);

        /// <summary>
        /// Destroys the Guitar object, releasing allocated memory.
        /// </summary>
        ~Guitar();

        /// <summary>
        /// Replaces all the strings in the guitar with the strings received as parameters.
        /// </summary>
        /// <param name="strings">Address of an unmodifiable array of GuitarString objects.</param>
        /// <param name="cntStrings">Number of GuitarString objects in the array.</param>
        /// <returns>A reference to the modified Guitar object.</returns>
        Guitar &reString(const GuitarString *strings, int cntStrings);

        /// <summary>
        /// Replaces a single string at the specified index with the GuitarString object received as a parameter.
        /// </summary>
        /// <param name="aString">A reference to an unmodifiable GuitarString object.</param>
        /// <param name="idx">The index of the GuitarString object to be replaced.</param>
        /// <returns>A reference to the modified Guitar object.</returns>
        Guitar &reString(const GuitarString &aString, int idx);

        /// <summary>
        /// Removes all the strings from the guitar.
        /// </summary>
        /// <returns>A reference to the modified Guitar object.</returns>
        Guitar &deString();

        /// <summary>
        /// Checks if the guitar has at least one string.
        /// </summary>
        /// <returns>True if the guitar has strings; false otherwise.</returns>
        bool isStrung() const;

        /// <summary>
        /// Inserts the content of the current instance into the parameter.
        /// </summary>
        /// <param name="out">A reference to an object of type std::ostream.</param>
        /// <returns>A reference to the modified std::ostream object.</returns>
        std::ostream &display(std::ostream &out = std::cout) const;
    };

} // namespace seneca

#endif // SENECA_GUITAR_H
