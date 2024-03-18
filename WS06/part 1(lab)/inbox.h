#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H

#include "email.h"

namespace seneca
{

    class Inbox
    {
    private:
        // Pointer to dynamically allocated array of emails
        Email *m_emails;
        // Number of emails in the inbox
        int m_cntEmails;

    public:
        /// <summary>
        /// Default constructor for the Inbox class.
        /// </summary>
        Inbox();

        /// <summary>
        /// Copy constructor for the Inbox class.
        /// </summary>
        /// <param name="other">The Inbox object to be copied.</param>
        Inbox(const Inbox &other);

        /// <summary>
        /// Assignment operator for the Inbox class.
        /// </summary>
        /// <param name="other">The Inbox object to be assigned.</param>
        /// <returns>A reference to the current Inbox object after assignment.</returns>
        Inbox &operator=(const Inbox &other);

        /// <summary>
        /// Destructor for the Inbox class.
        /// </summary>
        ~Inbox();

        /// <summary>
        /// Overloaded compound assignment operator to add an email to the inbox.
        /// </summary>
        /// <param name="email">The Email object to be added to the inbox.</param>
        /// <returns>A reference to the current Inbox object after addition.</returns>
        Inbox &operator+=(const Email &email);

        /// <summary>
        /// Overloaded addition operator to create a new inbox with an added email.
        /// </summary>
        /// <param name="email">The Email object to be added to the new inbox.</param>
        /// <returns>A new Inbox object with the specified email added.</returns>
        Inbox operator+(const Email &email) const;

        /// <summary>
        /// Loads emails from a file into the inbox.
        /// </summary>
        /// <param name="filename">The name of the file containing the emails.</param>
        void load(const char *filename);

        /// <summary>
        /// Saves emails from the inbox to a file.
        /// </summary>
        /// <param name="filename">The name of the file to save the emails to.</param>
        void save(const char *filename);

        /// <summary>
        /// Overloaded insertion operator to output the contents of the inbox.
        /// </summary>
        /// <param name="out">The output stream to write the inbox contents to.</param>
        /// <param name="inbox">The Inbox object to be output.</param>
        /// <returns>The output stream containing the inbox contents.</returns>
        friend std::ostream &operator<<(std::ostream &out, const Inbox &inbox);
    };

} // namespace seneca

#endif // SENECA_INBOX_H
