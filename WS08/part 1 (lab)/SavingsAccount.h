#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H

#include "Account.h"
#include <iostream>

namespace seneca
{

    /// <summary>
    /// Class representing a chequing account.
    /// </summary>
    class SavingsAccount : public Account
    {
        double interestRate;

    public:
        /// <summary>
        /// Constructs a savings account with the given initial balance and interest rate.
        /// </summary>
        /// <param name="initialBalance">The initial balance of the account.</param>
        /// <param name="rate">The interest rate to be applied to the balance.</param>
        SavingsAccount(double initialBalance, double rate);

        /// <summary>
        /// Applies month-end transactions to the account, deducting the monthly fee.
        /// </summary>
        void monthEnd() override;

        /// <summary>
        /// Inserts savings account information into an ostream object.
        /// </summary>
        /// <param name="os">The ostream object to insert into.</param>
        void display(std::ostream &) const override;
    };

}

#endif
