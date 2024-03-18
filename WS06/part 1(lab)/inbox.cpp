#include "inbox.h"
#include <fstream>

namespace seneca
{

    /// <summary>
    /// Default constructor for the Inbox class.
    /// Initializes the inbox with null pointer and zero email count.
    /// </summary>
    Inbox::Inbox()
    {
        m_emails = nullptr;
        m_cntEmails = 0;
    }

    /// <summary>
    /// Copy constructor for the Inbox class.
    /// Initializes the inbox with null pointer and zero email count, and then performs a deep copy of the other Inbox object.
    /// </summary>
    /// <param name="other">The Inbox object to be copied.</param>
    Inbox::Inbox(const Inbox &other)
    {
        m_emails = nullptr;
        m_cntEmails = 0;
        *this = other;
    }

    /// <summary>
    /// Destructor for the Inbox class.
    /// Deallocates memory used by the dynamically allocated array of emails.
    /// </summary>
    Inbox::~Inbox()
    {
        delete[] m_emails;
    }

    /// <summary>
    /// Assignment operator for the Inbox class.
    /// Performs a deep copy of the other Inbox object.
    /// </summary>
    /// <param name="other">The Inbox object to be assigned.</param>
    /// <returns>A reference to the current Inbox object after assignment.</returns>
    Inbox &Inbox::operator=(const Inbox &other)
    {
        if (this != &other)
        {
            delete[] m_emails;
            m_cntEmails = other.m_cntEmails;
            if (m_cntEmails > 0)
            {
                m_emails = new Email[m_cntEmails];
                for (int i = 0; i < m_cntEmails; ++i)
                {
                    m_emails[i] = other.m_emails[i];
                }
            }
            else
            {
                m_emails = nullptr;
            }
        }
        return *this;
    }

    /// <summary>
    /// Overloaded compound assignment operator to add an email to the inbox.
    /// </summary>
    /// <param name="email">The Email object to be added to the inbox.</param>
    /// <returns>A reference to the current Inbox object after addition.</returns>
    Inbox &Inbox::operator+=(const Email &email)
    {
        Email *temp = new Email[m_cntEmails + 1];
        for (int i = 0; i < m_cntEmails; ++i)
        {
            temp[i] = m_emails[i];
        }
        temp[m_cntEmails++] = email;
        delete[] m_emails;
        m_emails = temp;
        return *this;
    }

    /// <summary>
    /// Overloaded addition operator to create a new inbox with an added email.
    /// </summary>
    /// <param name="email">The Email object to be added to the new inbox.</param>
    /// <returns>A new Inbox object with the specified email added.</returns>
    Inbox Inbox::operator+(const Email &email) const
    {
        Inbox temp(*this);
        temp += email;
        return temp;
    }

    /// <summary>
    /// Loads emails from a file into the inbox.
    /// </summary>
    /// <param name="filename">The name of the file containing the emails.</param>
    void Inbox::load(const char *filename)
    {
        if (!filename)
            return;
        std::ifstream file(filename);
        if (file.is_open())
        {
            Email email;
            while (email.load(file))
            {
                *this += email;
            }
            file.close();
        }
    }

    /// <summary>
    /// Saves emails from the inbox to a file.
    /// </summary>
    /// <param name="filename">The name of the file to save the emails to.</param>
    void Inbox::save(const char *filename)
    {
        if (!filename)
            return;
        std::ofstream file(filename);
        if (file.is_open())
        {
            for (int i = 0; i < m_cntEmails; ++i)
            {
                file << m_emails[i];
            }
            file.close();
        }
    }

    /// <summary>
    /// Overloaded insertion operator to output the contents of the inbox.
    /// </summary>
    /// <param name="out">The output stream to write the inbox contents to.</param>
    /// <param name="inbox">The Inbox object to be output.</param>
    /// <returns>The output stream containing the inbox contents.</returns>
    std::ostream &operator<<(std::ostream &out, const Inbox &inbox)
    {
        for (int i = 0; i < inbox.m_cntEmails; ++i)
        {
            out << inbox.m_emails[i];
        }
        return out;
    }

} // namespace seneca
