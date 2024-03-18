#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H

#include <iostream>

namespace seneca
{

    /// <summary>
    /// Interface for bank account functionality.
    /// </summary>
    class iAccount
    {
    public:
        /// <summary>
        /// Adds a positive amount to the account balance.
        /// </summary>
        /// <param name="amount">The amount to be credited.</param>
        /// <returns>True if the transaction succeeds, false otherwise.</returns>
        virtual bool credit(double) = 0;

        /// <summary>
        /// Subtracts a positive amount from the account balance.
        /// </summary>
        /// <param name="amount">The amount to be debited.</param>
        /// <returns>True if the transaction succeeds, false otherwise.</returns>
        virtual bool debit(double) = 0;

        /// <summary>
        /// Applies month-end transactions to the account.
        /// </summary>
        virtual void monthEnd() = 0;

        /// <summary>
        /// Inserts account information into an ostream object.
        /// </summary>
        /// <param name="os">The ostream object to insert into.</param>
        virtual void display(std::ostream &os) const = 0;

        /// <summary>
        /// Virtual destructor to ensure proper cleanup of derived classes.
        /// </summary>
        virtual ~iAccount() {}
    };

    /// <summary>
    /// Creates an account based on the given type and initial balance.
    /// </summary>
    /// <param name="type">The type of account to create.</param>
    /// <param name="balance">The initial balance of the account.</param>
    /// <returns>A pointer to the created account.</returns>
    iAccount *CreateAccount(const char *, double);

}

#endif 
