#include "Account.h"

namespace seneca
{

    Account::Account(double initialBalance)
    {
        currentBalance = initialBalance >= 0 ? initialBalance : 0.0;
    }

    bool Account::credit(double amount)
    {

        if (amount <= 0)
            return false;

        currentBalance += amount;
        return true;
    }

    bool Account::debit(double amount)
    {

        if (amount <= 0 || amount > currentBalance)
            return false;

        currentBalance -= amount;
        return true;
    }

    double Account::balance() const
    {
        return currentBalance;
    }

}
