#include "Functionalities.h"
#include "Employee.h"
#include <algorithm> 


int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    
    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    //designation of the employee whose salary is the highest
    //Note : if there are 2 or max values, first max is considered
    auto itr = std::max_element(
        data1.begin(),
        data1.end(),
        [](const Employee& emp1, const Employee& emp2) {
            return emp1.salary() < emp2.salary();
        }
    ); //COMPARISON LOGIC OR COMPARATOR!

    std::cout << "Designation of max sal employee is: " << (*itr).designation();

    // if 2 employees emp1 and emp2 are compared, emp1 is greater than emp2 only if emp1's salary is greater than emp2's salary

    // now using raw pointer 

    //designation of the employee whose salary is the highest
    //Note : if there are 2 or max values, first max is considered
    auto itr2 = std::max_element(
        data2.begin(),
        data2.end(),
        [](const Employee* emp1, const Employee* emp2) {
            return emp1->salary() < emp2->salary();
        }
    ); //COMPARISON LOGIC OR COMPARATOR!

    std::cout << "Designation of max sal employee is: " << (*itr2).designation();


}
