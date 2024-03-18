#include "bankAccount.h"

namespace seneca
{

    /// <summary>
    /// defining constructor for BankAccount class.
    /// </summary>
    /// <param name="name">The name of the account owner. By default, it is nullptr.</param>
    /// <param name="checking">Boolean value indicating whether this is a checking account. Default is true.</param>
    BankAccount::BankAccount(const char *name, bool checking)
    {
        m_balance = 0;
        m_transactions = 0;
        m_checking = checking;

        // check if name is valid
        if (name != nullptr && std::strlen(name) > 0)
        {
            std::strcpy(m_userName, name);
            m_checking = checking;
            m_transactions = 0;
        }
        else
        {
            // else set empty character as first so no garbage value exists
            m_userName[0] = '\0';
        }
    }

    /// <summary>
    /// display the information about the current instance.
    /// </summary>
    void BankAccount::display() const
    {
        if (*this)
        {
            std::cout << m_userName << " -> $" << m_balance << " in " << (m_checking ? "checking" : "saving") << " account." << std::endl;
        }
    }

    /// <summary>
    /// operation overloading
    /// returns true if the account is open, false otherwise.
    /// </summary>
    BankAccount::operator bool() const
    {
        return (m_userName[0] != '\0');
    }

    /// <summary>
    /// operation overloading
    /// returns the balance if the account is open, or std::nan("") otherwise.
    /// </summary>
    BankAccount::operator double() const
    {
        if (*this)
            return m_balance;
        return std::nan(""); // https://docs.w3cub.com/cpp/numeric/math/nan for reference
    }

    /// <summary>
    /// operation overloading
    /// returns the name of the account owner if the account is open, or "Not Open" otherwise.
    /// </summary>
    BankAccount::operator const char *() const
    {
        if (*this)
            return m_userName;
        return "Not Open";
    }

    /// <summary>
    /// operation overloading
    /// returns the number of transactions performed in this account if open, or -1 otherwise.
    /// </summary>
    BankAccount::operator int() const
    {
        if (*this)
            return m_transactions;
        return -1;
    }

    /// <summary>
    /// operation overloading
    /// adds the specified amount to the account balance.
    /// </summary>
    /// <param name="amount">The amount to be added to the balance.</param>
    /// <returns>A reference to the current instance.</returns>
    BankAccount &BankAccount::operator+=(double amount)
    {
        if (*this)
        {
            m_balance += amount;
            ++m_transactions;
        }
        return *this;
    }

    /// <summary>
    /// operation overloading
    /// subtracts the specified amount from the account balance.
    /// </summary>
    /// <param name="amount">The amount to be subtracted from the balance.</param>
    /// <returns>A reference to the current instance.</returns>
    BankAccount &BankAccount::operator-=(double amount)
    {
        // reusing that += operator overloaded above ( can't do -= yet )
        return (*this += (-1 * amount));
    }

    /// <summary>
    /// operation overloading
    /// Adds the specified amount to a copy of the current instance and returns it.
    /// </summary>
    /// <param name="amount">The amount to be added to the balance.</param>
    /// <returns>An object of type BankAccount.</returns>
    BankAccount BankAccount::operator+(double amount) const
    {
        BankAccount result(*this);
        result += amount;
        return result;
    }

    /// <summary>
    /// operation overloading
    /// Adds interest to the account balance ( pre operator ).
    /// </summary>
    /// <returns>A reference to the current instance.</returns>
    BankAccount &BankAccount::operator++()
    {
        if (*this && m_balance > 0)
        {
            double interest = (m_checking ? 0.005 : 0.025) * m_balance;
            m_balance += interest;
        }
        return *this;
    }

    /// <summary>
    /// operation overloading
    /// adds interest to the account balance. ( post operator )
    /// </summary>
    /// <returns>An object of type BankAccount.</returns>
    BankAccount BankAccount::operator++(int)
    {
        BankAccount temp(*this);
        ++(*this);
        return temp;
    }

    /// <summary>
    /// operation overloading
    /// compares the balance of the current instance with the specified amount.
    /// </summary>
    /// <param name="amount">The amount to compare with.</param>
    /// <returns>True if the balance is greater than the specified amount, false otherwise.</returns>
    bool BankAccount::operator>(double amount) const
    {
        return (*this && m_balance > amount);
    }

    /// <summary>
    ///  function for greater-than comparison operator.
    /// </summary>
    /// <param name="amount">The amount to compare with.</param>
    /// <param name="account">Reference to a BankAccount object.</param>
    /// <returns>True if the amount is greater than the balance of the account, false otherwise.</returns>
    bool operator>(double amount, const BankAccount &account)
    {
        return (amount > static_cast<double>(account));
    }

}