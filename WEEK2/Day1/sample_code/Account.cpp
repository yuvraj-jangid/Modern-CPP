#include "Account.h"

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_username: " << rhs._username;
    return os;
}

Account::Account(std::string name)
:_username{username}, _userId(++counter)
{
}
