#include <iostream>
#include <iomanip>

#include "email.h"

namespace seneca
{

    /// <summary>
    /// Default constructor for the Email class.
    /// Initializes the subject pointer to nullptr.
    /// </summary>
    Email::Email()
    {
        m_subject = nullptr;
    }

    /// <summary>
    /// Copy constructor for the Email class.
    /// Initializes the subject pointer to nullptr, and then performs a deep copy of the other Email object.
    /// </summary>
    /// <param name="other">The Email object to be copied.</param>
    Email::Email(const Email &other)
    {
        m_subject = nullptr;
        *this = other;
    }

    /// <summary>
    /// Assignment operator for the Email class.
    /// Performs a deep copy of another Email object.
    /// </summary>
    /// <param name="other">The Email object to be assigned.</param>
    /// <returns>A reference to the current Email object after assignment.</returns>
    Email &Email::operator=(const Email &other)
    {
        if (this != &other)
        {
            std::strcpy(m_fromName, other.m_fromName);
            std::strcpy(m_fromAddress, other.m_fromAddress);
            std::strcpy(m_dateReceived, other.m_dateReceived);
            if (other.m_subject != nullptr)
            {
                m_subject = new char[std::strlen(other.m_subject) + 1];
                std::strcpy(m_subject, other.m_subject);
            }
            else
            {
                m_subject = nullptr;
            }
        }
        return *this;
    }

    /// <summary>
    /// Destructor for the Email class.
    /// Deallocates memory used by the dynamically allocated subject.
    /// </summary>
    Email::~Email()
    {
        delete[] m_subject;
    }

    /// <summary>
    /// Loads data from an input stream into the current Email object.
    /// </summary>
    /// <param name="in">The input stream containing the email data.</param>
    /// <returns>True if the data was loaded successfully, false otherwise.</returns>
    bool Email::load(std::istream &in)
    {
        char buffer[1000];
        in.getline(m_fromAddress, 100, ',');
        in.getline(m_fromName, 100, ',');
        in.getline(buffer, 1000, ',');
        in.getline(m_dateReceived, 20);
        if (in.good())
        {
            delete[] m_subject;
            m_subject = new char[std::strlen(buffer) + 1];
            std::strcpy(m_subject, buffer);
            return true;
        }
        else
        {
            *this = Email();
            return false;
        }
    }

    /// <summary>
    /// Overloaded insertion operator to output the contents of the email.
    /// </summary>
    /// <param name="out">The output stream to write the email contents to.</param>
    /// <param name="email">The Email object to be output.</param>
    /// <returns>The output stream containing the email contents.</returns>
    std::ostream &operator<<(std::ostream &out, const Email &email)
    {
        if (email.m_subject != nullptr)
        {
            out << std::right << std::setw(20) << std::setfill(' ') << email.m_fromName;
            out << std::setw(2) << "  " << std::left << std::setw(40) << email.m_fromAddress;
            out << std::setw(2) << "  " << std::left << std::setw(17) << email.m_dateReceived + 11; // +11 to only print hh::mm::ss
            out << email.m_subject << std::endl;
        }
        return out;
    }

} // namespace seneca
