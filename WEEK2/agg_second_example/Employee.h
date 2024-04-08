#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include "Project.h"
#include <functional>

class Employee
{
private:
    std::string _emp_id;
    std::string _emp_name;
    unsigned long _emp_salary;
    std::reference_wrapper<Project> _emp_project;
public:
    Employee() = default;
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee&& operator=(Employee&&) = delete;
    Employee(Employee&&) = delete;    
    ~Employee() = default;

    Employee(std::string emp_id, std::string emp_name, unsigned long emp_salary, std::reference_wrapper<Project> emp_project);

    std::string empId() const { return _emp_id; }

    std::string empName() const { return _emp_name; }

    unsigned long empSalary() const { return _emp_salary; }

    std::reference_wrapper<Project> empProject() const { return _emp_project; }
    void setEmpProject(const std::reference_wrapper<Project> &emp_project) { _emp_project = emp_project; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
    
};

#endif // EMPLOYEE_H
