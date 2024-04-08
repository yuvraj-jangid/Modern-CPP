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

    // result 

    EmployeeContainer result1(data1.size()); // destination is of same size as source 
    std::copy(
        data1.begin(),
        data1.end(),
        result1.begin()
    );

    // copy all elements from beginning of data1 up to but not including 
}
