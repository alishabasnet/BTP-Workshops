#include <cstring>
#include <iomanip>
#include <iostream>

#include "fridge.h"

namespace seneca
{
    /// <summary>
    /// Default constructor. Creates an empty fridge.
    /// </summary>
    Fridge::Fridge()
    {
        m_model = nullptr;
        m_foods = nullptr;
        m_cntFoods = 0;
        m_capacity = 0;
    }

    /// <summary>
    /// Custom constructor that initializes the fridge with the given model and capacity.
    /// </summary>
    /// <param name="model">Pointer to the model of the fridge.</param>
    /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
    Fridge::Fridge(const char *model, int capacity)
    {
        m_model = nullptr;
        m_foods = nullptr;
        m_cntFoods = 0;
        m_capacity = 0;
        setModel(model, capacity);
    }

    /// <summary>
    /// Custom constructor that initializes the fridge with an array of foods, model, and capacity.
    /// </summary>
    /// <param name="foods">Pointer to the array of Food objects to be stored in the fridge.</param>
    /// <param name="cntFoods">The size of the foods array.</param>
    /// <param name="model">Pointer to the model of the fridge.</param>
    /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
    Fridge::Fridge(const Food *foods, int cntFoods, const char *model, int capacity)
    {
        m_model = nullptr;
        m_foods = nullptr;
        m_cntFoods = 0;
        m_capacity = 0;

        setModel(model, capacity);
        for (int i = 0; i < cntFoods; ++i)
        {
            addFood(foods[i]);
        }
    }

    /// <summary>
    /// Destructor. Releases dynamic memory allocated by the fridge.
    /// </summary>
    Fridge::~Fridge()
    {
        delete[] m_model;
        delete[] m_foods;
    }

    /// <summary>
    /// Set the model and capacity of the fridge.
    /// </summary>
    /// <param name="model">Pointer to the model of the fridge.</param>
    /// <param name="capacity">The maximum capacity of the fridge, measured in kilograms.</param>
    void Fridge::setModel(const char *model, int capacity)
    {
        int len = std::strlen(model);
        if (model != nullptr && len > 0 && capacity >= 10)
        {
            delete[] m_model;
            m_model = new char[len + 1];
            std::strcpy(m_model, model);
            m_capacity = capacity;
        }
    }

    /// <summary>
    /// Check if the fridge contains a specific food or any food.
    /// </summary>
    /// <param name="theFood">Pointer to the name of the food to be checked. Default is nullptr to check if the fridge is not empty.</param>
    bool Fridge::hasFood(const char *theFood) const
    {
        if (theFood == nullptr)
        {
            return m_cntFoods > 0;
        }
        for (int i = 0; i < m_cntFoods; ++i)
        {
            if (std::strcmp(m_foods[i].m_name, theFood) == 0)
            {
                return true;
            }
        }
        return false;
    }

    /// <summary>
    /// Calculate the total weight of all foods in the fridge.
    /// </summary>
    int Fridge::getContentWeight() const
    {
        int totalWeight = 0;
        for (int i = 0; i < m_cntFoods; ++i)
        {
            totalWeight += m_foods[i].m_weight;
        }
        return totalWeight;
    }

    /// <summary>
    /// Add a Food object to the fridge if there is capacity.
    /// </summary>
    /// <param name="aFood">The Food object to be added to the fridge.</param>
    bool Fridge::addFood(const Food &aFood)
    {
        int totalWeight = getContentWeight();
        if (totalWeight + aFood.m_weight > m_capacity)
            return false;

        Food *foods = new Food[m_cntFoods + 1];
        std::memcpy(foods, m_foods, sizeof(Food) * m_cntFoods);
        foods[m_cntFoods++] = aFood;

        delete[] m_foods;
        m_foods = foods;
        return true;
    }

    /// <summary>
    /// Display the content of the fridge.
    /// </summary>
    /// <param name="out">Reference to the output stream where the content will be displayed. Default is std::cout.</param>
    std::ostream &Fridge::display(std::ostream &out) const
    {
        if (m_model == nullptr)
        {
            out << "The fridge object is in an empty state.\n";
        }
        else
        {
            out << "     Fridge model: " << m_model << "\n";
            out << "  Fridge capacity: " << m_capacity << "kg\n";

            out << "  Fill percentage: " << (100.0 * getContentWeight()) / m_capacity << "% full\n";
            out << "The list of foods:\n";
            for (int i = 0; i < m_cntFoods; ++i)
            {
                out << "  - " << m_foods[i].m_name << " (" << m_foods[i].m_weight << "kg)\n";
            }
        }
        return out;
    }

    /// <summary>
    /// Check if the fridge is at least 90% full.
    /// </summary>
    bool Fridge::isFull() const
    {
        return getContentWeight() >= 0.9 * m_capacity;
    }

}