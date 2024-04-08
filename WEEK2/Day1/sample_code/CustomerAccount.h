#ifndef CUSTOMER_H
#define CUSTOMER_H

class CustomerAccount
{
private:
    std::string _customerName;
    unsigned long _phoneNumber;
    Gender _gender;
public:
    CustomerAccount() = default;
    
    ~CustomerAccount() {}
};

#endif // CUSTOMER_H
