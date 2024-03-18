#ifndef FRIDGE_H
#define FRIDGE_H

#include <iostream>
#include "fridge.h"
#include "food.h"

namespace seneca
{
    /// <summary>
    /// Represents a fridge that manages a collection of foods of undetermined size.
    /// </summary>
    class Fridge
    {
        ///< Pointer to dynamically allocated memory for the model of the fridge.
        char *m_model;

        ///< The maximum capacity of the fridge, measured in kilograms.
        int m_capacity;

        ///< Pointer to dynamically allocated array of Food objects in the fridge.
        Food *m_foods;

        ///< The number of Food objects currently in the fridge.
        int m_cntFoods;

        ///< Calculate the total weight of all foods in the fridge.
        int getContentWeight() const;

    public:
        /// <summary>
        /// Default constructor. Creates an empty fridge.
        /// </summary>
        Fridge();

        /// <summary>
        /// Custom constructor that initializes the fridge with the given model and capacity.
        /// </summary>
        /// <param name="model">Pointer to the model of the fridge.</param>
        /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
        Fridge(const char *model, int capacity);

        /// <summary>
        /// Custom constructor that initializes the fridge with an array of foods, model, and capacity.
        /// </summary>
        /// <param name="foods">Pointer to the array of Food objects to be stored in the fridge.</param>
        /// <param name="cntFoods">The size of the foods array.</param>
        /// <param name="model">Pointer to the model of the fridge.</param>
        /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
        Fridge(const Food *foods, int cntFoods, const char *model, int capacity);

        /// <summary>
        /// Destructor. Releases dynamic memory allocated by the fridge.
        /// </summary>
        ~Fridge();

        /// <summary>
        /// Adds a new Food object to the fridge if there is capacity.
        /// </summary>
        /// <param name="aFood">The Food object to be added to the fridge.</param>
        bool addFood(const Food &aFood);

        /// <summary>
        /// Sets the model and capacity of the fridge.
        /// </summary>
        /// <param name="model">Pointer to the model of the fridge.</param>
        /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
        void setModel(const char *model, int capacity);

        /// <summary>
        /// Checks if the fridge is at least 90% full.
        /// </summary>
        bool isFull() const;

        /// <summary>
        /// Checks if the fridge contains a specific food or any food.
        /// </summary>
        /// <param name="theFood">Pointer to the name of the food to be checked. Default is nullptr to check if the fridge is not empty.</param>
        bool hasFood(const char *theFood = nullptr) const;

        /// <summary>
        /// Displays the content of the fridge.
        /// </summary>
        /// <param name="out">Reference to the output stream where the content will be displayed.</param>
        std::ostream &display(std::ostream &out = std::cout) const;
    };
}

#endif // FRIDGE_H
