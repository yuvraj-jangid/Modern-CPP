//**********************count_if*********************

#include <numeric>
#include <algorithm>
#include "Functionalities.h"


int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;


    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    //count instances matching a condition
    /*
    1) std::count_if
        count instances matching with given condition
        condition is written as 
    */

    int count = std::count_if(
        data1.begin(),
        data1.end(),
        [](const Employee& emp) {return emp.salary() > 40000.0f;}
    )


}


