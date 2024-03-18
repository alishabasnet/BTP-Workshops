#include "SavingsAccount.h"
#include <iomanip>

namespace seneca
{

    SavingsAccount::SavingsAccount(const char *name, const Date &openDate, const DepositInfo &depInfo, double balance, double interest, const Date &interestDate)
        : BankAccount(name, openDate, depInfo, balance)
    {
        m_interest = interest;
        m_interestDate = interestDate;
    }

    double SavingsAccount::getInterest() const
    {
        return m_interest;
    }

    Date SavingsAccount::getInterestDate() const
    {
        return m_interestDate;
    }

    void SavingsAccount::applyInterest(const Date &today)
    {
        double oldBalance = getBalance();
        double interestAmount = oldBalance * m_interest;
        double newBalance = oldBalance + interestAmount;
        setBalance(newBalance);

        std::cout << "   ";
        writeCurrency(std::cout, oldBalance);
        std::cout << " + ";
        writeCurrency(std::cout, interestAmount);
        std::cout << " (" << m_interest << "%) = ";
        writeCurrency(std::cout, newBalance);
        std::cout << " | " << m_interestDate << " => " << today;

        std::cout << std::endl;
        m_interestDate = today;
    }

    std::ostream &SavingsAccount::write(std::ostream &out) const
    {
        BankAccount::write(out);
        out << " | " << std::fixed << std::setprecision(3) << m_interest << "% | " << m_interestDate;
        return out;
    }

    std::istream &SavingsAccount::read(std::istream &in)
    {
        BankAccount::read(in);
        std::cout << "Interest Date ";
        in >> m_interestDate;

        std::cout << "Interest Rate: ";
        in >> m_interest;
        return in;
    }

    std::istream &operator>>(std::istream &in, SavingsAccount &account)
    {
        return account.read(in);
    }

    std::ostream &operator<<(std::ostream &out, const SavingsAccount &account)
    {
        return account.write(out);
    }

}
