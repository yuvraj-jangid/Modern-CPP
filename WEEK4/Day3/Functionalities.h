#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include <vector>
#include <memory>

//Container 
using EmployeeContainer = std::vector<Employee>;
//raw pointer
using EmployeePointerContainer = std::vector<Employee*>;
//shared pointer
using Employeesmtptr = std::shared_ptr<Employee>;
using EmployeeSmartPointerContainer = std::vector<Employeesmtptr>;

void CreateEmployeeContainer(Employee& data1){

}

void CreateEmployeePointer(Employee& data2){

}

void CreateEmployeeSmartPointer(Employee& data3){

}

#endif // FUNCTIONALITIES_H
