#ifndef ACCOUNT_H
#define ACCOUNT_H

/*
    _id
    _username
    static counter
    disable all speacial member except destructor
    << out operator
    RegisterAccount() = 0
*/

#include <iostream>

class Account
{
private:
    /* data */
    static unsigned long counter; //no. of accounts
    unsigned long _userId;
    std::string _username;
public:
    Account() = default;
    Account(const Account&) = delete;
    Account& operator=(const Account&) = delete;
    Account&& operator=(Account&&) = delete;
    Account(Account&&) = delete;    
    ~Account() = default;

    explicit Account(std::string name); //explicit parametrized constructor

    virtual void RegisterAccount() = 0;

    static unsigned long getCounter() { return Account::counter; } 

    unsigned long userId() const { return _userId; }
    void setUserId(unsigned long userId) { _userId = userId; }

    std::string username() const { return _username; }
    void setUsername(const std::string &username) { _username = username; }

    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);

    
};

#endif // ACCOUNT_H
