#include <iomanip>
#include "SavingsAccount.h"

namespace seneca
{

    SavingsAccount::SavingsAccount(double initialBalance, double rate) : Account(initialBalance)
    {
        interestRate = rate >= 0 ? rate : 0.0;
    }

    void SavingsAccount::monthEnd()
    {
        double interestEarned = balance() * interestRate;
        credit(interestEarned);
    }

    void SavingsAccount::display(std::ostream &os) const
    {
        os << "Account type: Savings\n";
        os << "Balance: $" << std::fixed << std::setprecision(2) << balance() << "\n";
        os << "Interest Rate (%): " << std::fixed << std::setprecision(2) << interestRate * 100 << "\n";
    }

}
