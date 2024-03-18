#include <cstring>
#include <iostream>

#include "guitar.h"

namespace seneca
{

    /// <summary>
    /// Default constructor that initializes a Guitar object with the default model "Stratocaster".
    /// </summary>
    Guitar::Guitar()
    {
        std::strcpy(m_model, "Stratocaster");
    }

    /// <summary>
    /// Constructs a Guitar object with the given model.
    /// </summary>
    /// <param name="model">The model of the guitar.</param>
    Guitar::Guitar(const char *model)
    {
        if (model != nullptr && strlen(model) > 0)
        {
            std::strcpy(m_model, model);
        }
        else
        {
            std::strcpy(m_model, "");
        }
        m_strings = nullptr;
        m_cntStrings = 0;
    }

    /// <summary>
    /// Constructs a Guitar object with the given strings, count of strings, and model.
    /// </summary>
    /// <param name="strings">An array of GuitarString objects.</param>
    /// <param name="cntStrings">The count of strings.</param>
    /// <param name="model">The model of the guitar.</param>
    Guitar::Guitar(const GuitarString *strings, int cntStrings, const char *model)
    {
        // TODO: Remove this, checkinf if strcpy works or not
        // std::strncpy(m_model, model, sizeof(m_model) - 1);
        // m_model[sizeof(m_model) - 1] = '\0';
        std::strcpy(m_model, model);

        m_strings = new GuitarString[cntStrings];
        for (int i = 0; i < cntStrings; ++i)
        {
            m_strings[i] = strings[i];
        }
        m_cntStrings = cntStrings;
    }

    /// <summary>
    /// Destroys the Guitar object, releasing allocated memory.
    /// </summary>
    Guitar::~Guitar()
    {
        delete[] m_strings;
    }

    /// <summary>
    /// Queries if the guitar has at least one string.
    /// </summary>
    /// <returns>True if the guitar has at least one string; false otherwise.</returns>
    bool Guitar::isStrung() const
    {
        return m_strings != nullptr;
    }

    /// <summary>
    /// Removes all the strings from the current object.
    /// </summary>
    Guitar &Guitar::deString()
    {
        delete[] m_strings;
        m_strings = nullptr;
        m_cntStrings = 0;
        return *this;
    }

    /// <summary>
    /// Changes a single string with the one received as a parameter.
    /// </summary>
    /// <param name="aString">A reference to an unmodifiable object of type GuitarString.</param>
    /// <param name="idx">The index of the GuitarString object that must be replaced.</param>
    Guitar &Guitar::reString(const GuitarString &aString, int idx)
    {
        if (idx >= 0 && idx < m_cntStrings)
        {
            m_strings[idx] = aString;
        }
        return *this;
    }

    /// <summary>
    /// Removes all the strings from the current object and replaces them with new strings.
    /// </summary>
    /// <param name="strings">An array of GuitarString objects.</param>
    /// <param name="cntStrings">The count of strings.</param>
    Guitar &Guitar::reString(const GuitarString *strings, int cntStrings)
    {
        delete[] m_strings;
        m_strings = new GuitarString[cntStrings];
        for (int i = 0; i < cntStrings; ++i)
        {
            m_strings[i] = strings[i];
        }
        m_cntStrings = cntStrings;
        return *this;
    }

    /// <summary>
    /// Inserts into the parameter the content of the current instance.
    /// </summary>
    /// <param name="out">A reference to an object of type std::ostream.</param>
    /// <returns>A reference to the object received as a parameter.</returns>
    std::ostream &Guitar::display(std::ostream &out) const
    {
        if (std::strlen(m_model) == 0)
        {
            out << "Empty guitar object!" << std::endl;
        }

        else
        {
            out << "Guitar Model: " << m_model << std::endl;

            if (m_cntStrings == 0)
            {
                out << "Guitar cannot be used yet because it has no strings." << std::endl;
            }
            else
            {

                out << "Strings:" << std::endl;
                for (int i = 0; i < m_cntStrings; ++i)
                {
                    out << " #" << i + 1 << ". ";
                    out << m_strings[i].getMaterial();
                    out << " (" << m_strings[i].getGauge() << "mm)" << std::endl;
                }
            }
        }

        return out;
    }

} // namespace seneca
