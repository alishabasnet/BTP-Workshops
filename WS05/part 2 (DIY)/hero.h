/**
 * reference for `friend` function taken from
 * https://www.geeksforgeeks.org/friend-class-function-cpp
 * syntax: friend class Class_name
 */

#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "ability.h"

namespace seneca
{

    class Hero
    {
    private:
        /// Name of the hero
        char m_name[100];

        /// Array of abilities
        Ability *m_abilities;

        /// Number of abilities
        int m_cntAbilities;

        /// Level of the hero
        int m_level;

    public:
        /// <summary>
        /// Initializes the name to an empty string, the abilities to nullptr, the count of abilities to 0, and the level to 1.
        /// </summary>
        Hero();

        /// <summary>
        /// Initializes the hero with the provided name, abilities, and count of abilities.
        /// </summary>
        /// <param name="name">The name of the hero.</param>
        /// <param name="abilities">An array of abilities.</param>
        /// <param name="cntAbilities">The count of abilities.</param>
        Hero(const char *name, const Ability *abilities, int cntAbilities);

        /// <summary>
        /// Deallocates the memory used for the array of abilities.
        /// </summary>
        ~Hero();

        /// <summary>
        /// Prints information about the hero, including their name, level, total strength, and list of abilities.
        /// </summary>
        void display() const;

        /**
         *  operator overloading
         */

        /// <summary>
        /// Allows the hero to be converted to a C-string representing its name.
        /// </summary>
        operator const char *() const;

        /// <summary>
        /// Calculates and returns the total strength of the hero based on their abilities and level.
        /// </summary>
        operator int() const;

        /// <summary>
        /// Operator+= for adding an ability to the hero.
        /// Adds the given ability to the hero's list of abilities.
        /// </summary>
        /// <param name="ability">The ability to add.</param>
        /// <returns>A reference to the updated hero.</returns>
        Hero &operator+=(const Ability &ability);

        /// <summary>
        /// Operator+= for changing the hero's level.
        /// Increases the hero's level by the specified amount.
        /// </summary>
        /// <param name="lvlChange">The amount to change the level by.</param>
        /// <returns>A reference to the updated hero.</returns>
        Hero &operator+=(int lvlChange);

        /// <summary>
        /// Operator++ for increasing the hero's level by 1.
        /// Increases the hero's level by 1.
        /// </summary>
        /// <returns>A reference to the updated hero.</returns>
        Hero &operator++();

        /// <summary>
        /// Friend operator< for comparing two heroes' strengths.
        /// Compares the total strengths of two heroes.
        /// </summary>
        /// <param name="toCompare">The hero to be compared with.</param>
        /// <param name="h2">The second hero.</param>
        /// <returns>True if the first hero's total strength is less than the second hero's, false otherwise.</returns>
        bool operator<(const Hero &toCompare) const;

        /// <summary>
        /// Friend operator> for comparing two heroes' strengths.
        /// Compares the total strengths of two heroes.
        /// </summary>
        /// <param name="h1">The first hero.</param>
        /// <param name="h2">The second hero.</param>
        /// <returns>True if the first hero's total strength is greater than the second hero's, false otherwise.</returns>
        friend bool operator>(const Hero &h1, const Hero &h2);

        /// <summary>
        /// Friend operator>> for adding an ability to a hero.
        /// Adds the given ability to the hero's list of abilities.
        /// </summary>
        /// <param name="ability">The ability to add.</param>
        /// <param name="hero">The hero to add the ability to.</param>
        /// <returns>A reference to the updated hero.</returns>
        friend Hero &operator>>(const Ability &ability, Hero &hero);

        /// <summary>
        /// Friend operator<< for adding an ability to a hero.
        /// Adds the given ability to the hero's list of abilities.
        /// </summary>
        /// <param name="hero">The hero to add the ability to.</param>
        /// <param name="ability">The ability to add.</param>
        /// <returns>A reference to the updated hero.</returns>
        friend Hero &operator<<(Hero &hero, const Ability &ability);
    };

} // namespace seneca

#endif // SENECA_HERO_H
