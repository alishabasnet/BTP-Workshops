#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H

#include <iostream>
#include <cstring>

namespace seneca
{

    class Email
    {
    private:
        char m_fromName[100];    // Name of the sender
        char m_fromAddress[100]; // Email address of the sender
        char m_dateReceived[20]; // Date and time when the email was received
        char *m_subject;         // Subject of the email

    public:
        /// <summary>
        /// Default constructor for the Email class.
        /// Initializes member variables to default values.
        /// </summary>
        Email();

        /// <summary>
        /// Copy constructor for the Email class.
        /// Performs a deep copy of another Email object.
        /// </summary>
        /// <param name="other">The Email object to be copied.</param>
        Email(const Email &other);

        /// <summary>
        /// Assignment operator for the Email class.
        /// Performs a deep copy of another Email object.
        /// </summary>
        /// <param name="other">The Email object to be assigned.</param>
        /// <returns>A reference to the current Email object after assignment.</returns>
        Email &operator=(const Email &other);

        /// <summary>
        /// Destructor for the Email class.
        /// Deallocates memory used by the dynamically allocated subject.
        /// </summary>
        ~Email();

        /// <summary>
        /// Loads data from an input stream into the current Email object.
        /// </summary>
        /// <param name="in">The input stream containing the email data.</param>
        /// <returns>True if the data was loaded successfully, false otherwise.</returns>
        bool load(std::istream &in);

        /// <summary>
        /// Overloaded insertion operator to output the contents of the email.
        /// </summary>
        /// <param name="out">The output stream to write the email contents to.</param>
        /// <param name="email">The Email object to be output.</param>
        /// <returns>The output stream containing the email contents.</returns>
        friend std::ostream &operator<<(std::ostream &out, const Email &email);
    };

} // namespace seneca

#endif // SENECA_EMAIL_H
