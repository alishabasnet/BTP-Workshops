/**
 * help taken from internet for casting
 * https://www.geeksforgeeks.org/static_cast-in-cpp/
 * static_cast <dest_type> (source);
*/


#include "hero.h"
#include <iostream>

namespace seneca
{

    /// <summary>
    /// Initializes a new Hero object with default values.
    /// </summary>
    Hero::Hero()
    {
        m_level = 1;
        m_name[0] = '\0';
        m_cntAbilities = 0;
        m_abilities = nullptr;
    }

    /// <summary>
    /// Initializes a new Hero object with the specified name, abilities, and count of abilities.
    /// </summary>
    /// <param name="name">The name of the hero.</param>
    /// <param name="abilities">An array of abilities.</param>
    /// <param name="cntAbilities">The count of abilities.</param>
    Hero::Hero(const char *name, const Ability *abilities, int cntAbilities)
    {
        int i = 0;
        while (name[i] != '\0' && i < 99)
        {
            m_name[i] = name[i];
            i++;
        }
        m_name[i] = '\0';

        m_abilities = new Ability[cntAbilities];
        for (int j = 0; j < cntAbilities; ++j)
        {
            m_abilities[j] = abilities[j];
        }

        m_level = 1;
        m_cntAbilities = cntAbilities;
    }

    /// <summary>
    /// Deallocates dynamic memory allocated for m_abilities.
    /// </summary>
    Hero::~Hero()
    {
        delete[] m_abilities;
    }

    /// <summary>
    /// Conversion to const char* operator.
    /// </summary>
    /// <returns>The name of the hero as a C-style string.</returns>
    Hero::operator const char *() const
    {
        return m_name;
    }

    /// <summary>
    /// Conversion to int operator.
    /// Calculates and returns the total strength of the hero.
    /// </summary>
    /// <returns>The total strength of the hero.</returns>
    Hero::operator int() const
    {
        int totalStrength = 0;
        for (int i = 0; i < m_cntAbilities; ++i)
        {
            totalStrength += m_abilities[i].getStrength();
        }
        return totalStrength * m_level;
    }

    /// <summary>
    /// Operator+= for adding a new ability to the hero.
    /// </summary>
    /// <param name="ability">The ability to add.</param>
    /// <returns>A reference to the updated hero.</returns>
    Hero &Hero::operator+=(const Ability &ability)
    {
        // Resize m_abilities to accommodate the new ability
        Ability *abilityArray = new Ability[m_cntAbilities + 1];
        for (int i = 0; i < m_cntAbilities; ++i)
        {
            abilityArray[i] = m_abilities[i];
        }

        abilityArray[m_cntAbilities] = ability;
        delete[] m_abilities;
        m_abilities = abilityArray;
        m_cntAbilities++;
        return *this;
    }

    /// <summary>
    /// Operator+= for changing the level of the hero.
    /// </summary>
    /// <param name="lvlChange">The change in level.</param>
    /// <returns>A reference to the updated hero.</returns>
    Hero &Hero::operator+=(int lvlChange)
    {
        m_level += lvlChange;
        if (m_level < 1)
            m_level = 1;
        return *this;
    }

    /// <summary>
    /// Operator++ for increasing the level of the hero by 1.
    /// </summary>
    /// <returns>A reference to the updated hero.</returns>
    Hero &Hero::operator++()
    {
        m_level++;
        return *this;
    }

    /// <summary>
    /// Display function.
    /// Displays the details of the hero, including name, level, total strength, and abilities.
    /// </summary>
    void Hero::display() const
    {
        std::cout << m_name << " (lvl: " << m_level << ", str: " << static_cast<int>(*this) << ")\n";
        for (int i = 0; i < m_cntAbilities; ++i)
        {
            std::cout << "  - " << m_abilities[i].getName() << " (" << m_abilities[i].getStrength() << ")\n";
        }
    }

    /// <summary>
    /// Operator< for comparing two heroes' strengths.
    /// </summary>
    /// <param name="h1">The first hero.</param>
    /// <param name="h2">The second hero.</param>
    /// <returns>True if the total strength of the first hero is less than that of the second hero, false otherwise.</returns>
    bool operator<(const Hero &h1, const Hero &h2)
    {
        return static_cast<int>(h1) < static_cast<int>(h2);
    }

    /// <summary>
    /// Operator> for comparing two heroes' strengths.
    /// </summary>
    /// <param name="h1">The first hero.</param>
    /// <param name="h2">The second hero.</param>
    /// <returns>True if the total strength of the first hero is greater than that of the second hero, false otherwise.</returns>
    bool operator>(const Hero &h1, const Hero &h2)
    {
        return static_cast<int>(h1) > static_cast<int>(h2);
    }

    /// <summary>
    /// Operator>> for adding an ability to a hero.
    /// </summary>
    /// <param name="ability">The ability to add.</param>
    /// <param name="hero">The hero to add the ability to.</param>
    /// <returns>A reference to the updated hero.</returns>
    Hero &operator>>(const Ability &ability, Hero &hero)
    {
        hero += ability;
        return hero;
    }

    /// <summary>
    /// Operator<< for adding an ability to a hero.
    /// </summary>
    /// <param name="hero">The hero to add the ability to.</param>
    /// <param name="ability">The ability to add.</param>
    /// <returns>A reference to the updated hero.</returns>
    Hero &operator<<(Hero &hero, const Ability &ability)
    {
        hero += ability;
        return hero;
    }

} // namespace seneca
