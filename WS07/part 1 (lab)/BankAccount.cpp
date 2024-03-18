#include <iomanip>
#include <string.h>
#include "BankAccount.h"

namespace seneca
{
    BankAccount::BankAccount(const char *name, const Date &openDate, const DepositInfo &depInfo, double balance)
    {
        m_openDate = openDate;
        m_depInfo = depInfo;
        m_balance = balance;

        int len = sizeof(m_name);
        strncpy(m_name, name, len);
        m_name[len - 1] = '\0';
    }

    double BankAccount::getBalance() const
    {
        return m_balance;
    }

    void BankAccount::setBalance(double newBalance)
    {
        m_balance = newBalance;
    }

    void BankAccount::writeCurrency(std::ostream &out, double amount) const
    {
        std::streamsize originalPrecision = std::cout.precision();
        out << std::fixed << std::setprecision(2) << "$" << amount;
        std::cout.precision(originalPrecision);
    }

    std::ostream &BankAccount::write(std::ostream &out) const
    {
        out << ">> "<< m_name << " | ";
        writeCurrency(out, m_balance);
        out << " | " << m_openDate << " | " << m_depInfo;
        return out;
    }

    std::istream &BankAccount::read(std::istream &in)
    {
        std::cout << "Name: ";
        in.getline(m_name, sizeof(m_name));
        std::cout << "Opening Balance: ";
        in >> m_balance;

        std::cout << "Date Opened ";
        m_openDate.read(in);
        m_depInfo.read(in);

        return in;
    }

    std::istream &operator>>(std::istream &in, BankAccount &account)
    {
        return account.read(in);
    }

    std::ostream &operator<<(std::ostream &out, const BankAccount &account)
    {
        return account.write(out);
    }

}
