#include "Functionalities.h"
#include "Employee.h"
#include <numeric> // library for acuumulate

// *************the word accumulate means to gather**************** 

int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    
    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    /*
        rule 1 : default operation is binary +
    */
   //total salary for all emoloyees
   std::cout << std::accumulate(
    data1.begin(),
    data1.end(),
    0.0f, // initial value for starting an operation 
    [](float answer_upto_current_point, const Employee emp){
        return answer_upto_current_point + emp.salary();
    }
   );

   std::cout << std::accumulate(
    data2.begin(),
    data2.end(),
    0.0f,
    [](float answer_upto_current_point, const Employee* emp){
        return answer_upto_current_point + emp->salary();
    }
   );


/*
    functional programming 
        -map : applying a logic (function) on all items in data collection (one by one)

        -filter : extracting items that satisfy a condition from the data collection 

        -reduce : collection/ summarizing/ gathering/ converting multiple items into a single item based on binary operation

        eg : 10, 20, 30, 60, 76
            - reduce 5 numbers into 1 number by summation aggregation
            - reduce 5 numbers into 1 by product aggregation
*/
}
