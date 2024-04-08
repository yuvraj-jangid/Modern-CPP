#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee
{
private:
    std::string _name {""};
    float _salary{0.0f};
    std::string _designation{""};
    int _exp_years{-1};
public:
    Employee() = default; // default constructor enable
    Employee(const Employee&) = delete; //disabled copy constructor
    Employee(Employee&&) = delete; //disabled move constructor
    Employee& operator=(const Employee&) = delete; //deleted copy assignment operator
    Employee& operator=(Employee&&) = delete; //c++ brand new, deleted move assignment operator
    ~Employee() = default; //destructor enabled

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    Employee(std::string name, float salary, std::string designation, int exp_years)
    : _name{name}, _salary{salary}, _designation{designation}, _exp_years{exp_years} {}

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    std::string designation() const { return _designation; }

    void setName(const std::string &name) { _name = name; }

    void setSalary(float salary) { _salary = salary; }

    int expYears() const { return _exp_years; }
    
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_name: " << rhs._name
       << " _salary: " << rhs._salary
       << " _designation: " << rhs._designation
       << " _exp_years: " << rhs._exp_years;
    return os;
}

#endif // EMPLOYEE_H
