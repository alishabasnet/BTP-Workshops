#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include <iostream>
#include "DepositUtility.h"

namespace seneca
{

    class BankAccount
    {
    private:
        char m_name[100];
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        double getBalance() const;
        void setBalance(double newBalance);
        void writeCurrency(std::ostream &out, double amount) const;

    public:
        BankAccount(const char *name, const Date &openDate, const DepositInfo &depInfo, double balance);
        std::ostream &write(std::ostream &out) const;
        std::istream &read(std::istream &in);
        friend std::istream &operator>>(std::istream &in, BankAccount &account);
        friend std::ostream &operator<<(std::ostream &out, const BankAccount &account);
    };

}

#endif // SENECA_BANKACCOUNT_H
