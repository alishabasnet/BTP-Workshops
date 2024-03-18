#include "ability.h"

namespace seneca
{

    /// <summary>
    /// Default constructor.
    /// Initializes the name to an empty string and the strength to 0.
    /// </summary>
    Ability::Ability()
    {
        m_strength = 0;
        m_name[0] = '\0';
    }

    /// <summary>
    /// Custom constructor.
    /// Initializes the name and strength of the ability.
    /// </summary>
    /// <param name="name">The name of the ability.</param>
    /// <param name="strength">The strength of the ability.</param>
    Ability::Ability(const char *name, int strength) : m_strength(strength)
    {
        int i = 0;
        while (name[i] != '\0' && i < 99)
        {
            m_name[i] = name[i];
            i++;
        }

        m_name[i] = '\0';
    }

    /// <summary>
    /// Getter for ability name.
    /// </summary>
    /// <returns>The name of the ability.</returns>
    const char *Ability::getName() const
    {
        return m_name;
    }

    /// <summary>
    /// Getter for ability strength.
    /// </summary>
    /// <returns>The strength of the ability.</returns>
    int Ability::getStrength() const
    {
        return m_strength;
    }

    

} // namespace seneca
