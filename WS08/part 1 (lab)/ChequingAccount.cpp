#include <iomanip>
#include "ChequingAccount.h"

namespace seneca
{

    ChequingAccount::ChequingAccount(double initialBalance, double fee, double initialMonthlyFee) : Account(initialBalance)
    {
        transactionFee = fee >= 0 ? fee : 0.0;
        monthlyFee = initialMonthlyFee >= 0 ? initialMonthlyFee : 0.0;
    }

    bool ChequingAccount::credit(double amount)
    {

        if (amount <= 0 || !Account::credit(amount))
            return false;

        Account::debit(transactionFee);
        return true;
    }

    bool ChequingAccount::debit(double amount)
    {

        if (amount <= 0 || !Account::debit(amount) || amount + transactionFee > balance())
            return false;

        Account::debit(transactionFee);
        return true;
    }

    void ChequingAccount::monthEnd()
    {
        Account::debit(monthlyFee);
    }

    void ChequingAccount::display(std::ostream &os) const
    {
        os << "Account type: Chequing\n";
        os << "Balance: $" << std::fixed << std::setprecision(2) << balance() << "\n";
        os << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << transactionFee << "\n";
        os << "Monthly Fee: " << std::fixed << std::setprecision(2) << monthlyFee << "\n";
    }

}
