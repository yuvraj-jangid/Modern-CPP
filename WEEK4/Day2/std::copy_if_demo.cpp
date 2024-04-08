#include "Functionalities.h"
#include "Employee.h"
#include <algorithm> // library for most of the operations except accumulate 


int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    
    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    /*
        1) this is a copy operation. copy semantics has to be supported
        2) we don't know how many instances will satisfy the condition
        3) 

    */

    EmployeeContainer result1(data1.size()); // SEGMENTATION FAULT

    //condition copy
    auto itr = std::copy_if(
        data1.begin(),
        data1.end(),
        result1.begin(),
        [](const Employee& emp) {return emp.salary() > 40000;}
    );

    // Now we have to fix the size difference 

    std::size_t actual_size = std::distance(result1.begin(), itr);

    result1.resize(actual_size); // discard elements beyond last copy


 // Let's do with raw pointer now
    EmployeeContainer result2(data2.size()); // SEGMENTATION FAULT

    //condition copy
    auto itr2 = std::copy_if(
        data2.begin(),
        data2.end(),
        result2.begin(),
        [](const Employee* emp) {return emp->salary() > 40000;}
    );

    // Now we have to fix the size difference 

    std::size_t actual_size = std::distance(result2.begin(), itr2);

    result1.resize(actual_size); // discard elements beyond last copy

}
