#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H

#include "Account.h"
#include <iostream>

namespace seneca
{

    /// <summary>
    /// Class representing a chequing account.
    /// </summary>
    class ChequingAccount : public Account
    {
        double transactionFee;
        double monthlyFee;

    public:
        /// <summary>
        /// Constructs a chequing account with the given initial balance, transaction fee, and monthly fee.
        /// </summary>
        /// <param name="initialBalance">The initial balance of the account.</param>
        /// <param name="fee">The transaction fee to be applied to each transaction.</param>
        /// <param name="monthlyFee">The monthly fee to be applied to the account.</param>
        ChequingAccount(double initialBalance, double fee, double monthlyFee);

        bool credit(double amount) override;
        bool debit(double amount) override;

        /// <summary>
        /// Applies month-end transactions to the account, deducting the monthly fee.
        /// </summary>
        void monthEnd() override;

        /// <summary>
        /// Inserts chequing account information into an ostream object.
        /// </summary>
        /// <param name="os">The ostream object to insert into.</param>
        void display(std::ostream &) const override;
    };

}

#endif
