#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "iAccount.h"

namespace seneca
{

    class Account : public iAccount
    {
        double currentBalance;

    protected:
        /// <summary>
        /// Returns the current balance of the account.
        /// </summary>
        double balance() const;

    public:
        /// <summary>
        /// Constructs an account with the given initial balance.
        /// </summary>
        /// <param name="initialBalance">The initial balance of the account.</param>
        Account(double initialBalance = 0.0);

        /// <summary>
        /// Adds a positive amount to the account balance.
        /// </summary>
        /// <param name="amount">The amount to be credited.</param>
        /// <returns>True if the transaction succeeds, false otherwise.</returns>
        bool credit(double amount) override;

        /// <summary>
        /// Subtracts a positive amount from the account balance.
        /// </summary>
        /// <param name="amount">The amount to be debited.</param>
        /// <returns>True if the transaction succeeds, false otherwise.</returns>
        bool debit(double amount) override;
    };

}

#endif
