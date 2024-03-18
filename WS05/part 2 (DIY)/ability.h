#ifndef SENECA_ABILITY_H
#define SENECA_ABILITY_H

namespace seneca
{

    class Ability
    {
    private:
        /// Name of the ability
        char m_name[100];

        /// Strength of the ability
        int m_strength;

    public:
        /// <summary>
        /// Default constructor.
        /// Initializes the name to an empty string and the strength to 0.
        /// </summary>
        Ability();

        /// <summary>
        /// Custom constructor.
        /// Initializes the name and strength of the ability.
        /// </summary>
        /// <param name="name">The name of the ability.</param>
        /// <param name="strength">The strength of the ability.</param>
        Ability(const char *name, int strength);

        /// <summary>
        /// Getter function for ability name.
        /// </summary>
        /// <returns>The name of the ability.</returns>
        const char *getName() const;

        /// <summary>
        /// Getter function for ability strength.
        /// </summary>
        /// <returns>The strength of the ability.</returns>
        int getStrength() const;
    };

} // namespace seneca

#endif // SENECA_ABILITY_H
