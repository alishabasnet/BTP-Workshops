#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H

#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca
{

    class SavingsAccount : public BankAccount
    {
    private:
        double m_interest;
        Date m_interestDate;

    public:
        SavingsAccount(const char *name, const Date &openDate, const DepositInfo &depInfo, double balance, double interest, const Date &interestDate);
        double getInterest() const;
        Date getInterestDate() const;
        void applyInterest(const Date &today);
        std::ostream &write(std::ostream &out) const;
        std::istream &read(std::istream &in);
        friend std::istream &operator>>(std::istream &in, SavingsAccount &account);
        friend std::ostream &operator<<(std::ostream &out, const SavingsAccount &account);
    };

}

#endif
