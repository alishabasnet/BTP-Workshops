#include <iostream>
#include <cstring>
#include <iomanip>
#include "car.h"

using namespace std;

namespace seneca
{

    /// <summary>
    /// Check if the `Car` object contains valid data and can be used.
    /// </summary>
    /// <returns>`true` if the object contains valid data; `false` otherwise.</returns>
    bool Car::isEmpty()
    {
        return m_makeModel == nullptr;
    }

    /// <summary>
    /// Sets the object into an empty state.  The object is not valid anymore and should
    ///     not be used until it receives valid data.
    /// </summary>
    void Car::setEmpty()
    {
        // 1. Make license plate empty
        strcpy(m_licencePlate, "");

        // 2. Reset dynamic strings
        // delete[] m_makeModel;
        // delete[] m_problemDesc;

        // 3. reset pointer references and values
        m_cost = 0.0;
        m_makeModel = nullptr;
        m_problemDesc = nullptr;
        m_objectStatus = INVALID_REASON__EMPTY;
    }

    void Car::set(const char *plateNo, const char *model, const char *desc, double serviceCost)
    {
        Car::deallocateMemory();

        if (plateNo == nullptr || plateNo[0] == '\0')
            m_objectStatus = INVALID_REASON__PLATE;
        else if (model == nullptr || model[0] == '\0')
            m_objectStatus = INVALID_REASON__MODEL;
        else if (desc == nullptr || desc[0] == '\0')
            m_objectStatus = INVALID_REASON__DESC;
        else
        {
            strncpy(m_licencePlate, plateNo, 8);
            m_licencePlate[8] = '\0';

            m_makeModel = new char[strlen(model) + 1];
            strcpy(m_makeModel, model);

            m_problemDesc = new char[strlen(desc) + 1];
            strcpy(m_problemDesc, desc);

            m_cost = serviceCost;
            m_objectStatus = VALID_OBJECT;
        }
    }

    void Car::display()
    {
        // Save current formatting options
        std::ios_base::fmtflags originalFlags = std::cout.flags();
        std::streamsize originalPrecision = std::cout.precision();
        std::streamsize originalWidth = std::cout.width();
        char originalFill = std::cout.fill();

        if (m_objectStatus == VALID_OBJECT)
        {

            // Display the formatted output

            // Set the filling character to ' '
            std::cout.fill(' ');
            std::cout << "| ";
            std::cout.width(8);
            std::cout << std::right << m_licencePlate << " | ";

            // Set the filling character to '.'
            std::cout.fill('.');

            std::cout.width(20);
            std::cout << std::left << m_makeModel << " | ";

            std::cout.width(34);
            std::cout << std::setfill('.') << std::right << m_problemDesc << " | ";

            std::cout << std::fixed << std::setprecision(2);
            std::cout.width(8);
            std::cout << std::right << m_cost << " |";
        }
        else
        {
            // set fill to whitespace
            std::cout.fill(' ');

            std::cout << "| ";
            std::cout.width(86);
            std::cout << std::left << m_objectStatus << std::right << "|";
        }

        // Restore original formatting options that were change
        std::cout.precision(originalPrecision);
        std::cout.width(originalWidth);
        std::cout.flags(originalFlags);
        std::cout.fill(originalFill);
    }

    /// <summary>
    /// Deallocates all the dynamic memory used by the object, and set the object
    ///   to an empty state.
    /// </summary>
    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        delete[] m_problemDesc;

        // 2. Empty car
        Car::setEmpty();
    }

} // namespace seneca