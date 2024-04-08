#include "Employee.h"

Employee::Employee(std::string emp_id, std::string emp_name, unsigned long emp_salary, std::reference_wrapper<Project> emp_project)
: _emp_id{emp_id}, _emp_name{emp_name}, _emp_salary{emp_salary}, _emp_project{emp_project}
{
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_emp_id: " << rhs._emp_id
       << " _emp_name: " << rhs._emp_name
       << " _emp_salary: " << rhs._emp_salary
       << " _emp_project: " << rhs._emp_project;
    return os;
}
