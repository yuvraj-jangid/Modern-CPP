// ************std::all_of******************

/*
check if all instances meet a condition.

*/
#include "Functionalities.h"
#include "Employee.h"
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>


int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;


    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    std::cout << std::all_of(
    data1.begin(),
    data1.end(),
    [](const Employee& emp){ return emp.salary() > 40000.0f; }
   );

    std::cout << std::all_of(
    data2.begin(),
    data2.end(),
    [](const Employee* emp){ return emp->salary() > 40000.0f; }
   );

    std::cout << std::all_of(
    data3.begin(),
    data3.end(),
    [](const Employeesmtptr& emp){ return emp->salary() > 40000.0f; }
   );

}
