

/**
 * operator: explicit ( used for operator overloading )
 * found during my research on operator overloading
 * https://www.ibm.com/docs/en/i/7.1?topic=only-explicit-specifier-c for reference
 */

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include <iostream>
#include <cstring>
#include <cmath>

namespace seneca
{

    class BankAccount
    {
    private:
        // Stores the name of the account owner.
        char m_userName[101];

        // Stores the balance of the account.
        double m_balance;

        // Indicates whether this is a checking account.
        bool m_checking;

        // Stores the number of transactions performed on the account.
        int m_transactions;

    public:
        /// <summary>
        /// custom constructor for BankAccount class.
        /// </summary>
        /// <param name="name">The name of the account owner. By default, it is nullptr.</param>
        /// <param name="checking">Boolean value indicating whether this is a checking account. Default is true.</param>
        BankAccount(const char *name = nullptr, bool checking = false);

        /// <summary>
        /// Displays the information about the current instance.
        /// </summary>
        void display() const;

        /// <summary>
        /// returns true if the account is open, false otherwise.
        /// </summary>
        explicit operator bool() const;

        /// <summary>
        /// returns the balance if the account is open, or std::nan("") otherwise.
        /// </summary>
        explicit operator double() const;

        /// <summary>
        /// returns the name of the account owner if the account is open, or "Not Open" otherwise.
        /// </summary>
        explicit operator const char *() const;

        /// <summary>
        /// returns the number of transactions performed in this account if open, or -1 otherwise.
        /// </summary>
        explicit operator int() const;

        /// <summary>
        /// Modifier that adds the specified amount to the account balance.
        /// </summary>
        /// <param name="amount">The amount to be added to the balance.</param>
        /// <returns>A reference to the current instance.</returns>
        BankAccount &operator+=(double amount);

        /// <summary>
        /// Modifier that subtracts the specified amount from the account balance.
        /// </summary>
        /// <param name="amount">The amount to be subtracted from the balance.</param>
        /// <returns>A reference to the current instance.</returns>
        BankAccount &operator-=(double amount);

        /// <summary>
        /// Adds the specified amount to a copy of the current instance and returns it.
        /// </summary>
        /// <param name="amount">The amount to be added to the balance.</param>
        /// <returns>An object of type BankAccount.</returns>
        BankAccount operator+(double amount) const;

        /// <summary>
        /// Adds interest to the account balance ( pre operator ).
        /// </summary>
        /// <returns>A reference to the current instance.</returns>
        BankAccount &operator++();

        /// <summary>
        /// adds interest to the account balance. ( post operator )
        /// </summary>
        /// <returns>An object of type BankAccount.</returns>
        BankAccount operator++(int);

        /// <summary>
        /// compares the balance of the current instance with the specified amount.
        /// </summary>
        /// <param name="amount">The amount to compare with.</param>
        /// <returns>True if the balance is greater than the specified amount, false otherwise.</returns>
        bool operator>(double amount) const;

        /// <summary>
        ///  function for greater-than comparison operator.
        /// </summary>
        /// <param name="amount">The amount to compare with.</param>
        /// <param name="account">Reference to a BankAccount object.</param>
        /// <returns>True if the amount is greater than the balance of the account, false otherwise.</returns>
        friend bool operator>(double amount, const BankAccount &account);
    };

} // namespace seneca

#endif // SENECA_BANKACCOUNT_H
