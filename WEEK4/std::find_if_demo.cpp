// ******************find_if****************************

#include <numeric>
#include <algorithm>
#include "Functionalities.h"
#include <functional>


void Search(const EmployeeContainer& data, std::function<bool(const Employee&)>){
    auto itr = std::find_if(
    data.begin(),
    data.end(),
    [](const Employee& emp){ return emp.designation() = "Trainer";}
   );
   if(itr == data.end()){
        std::cerr << "Object not found\n";
   }
   else{
    std::cout << "Object found" << *itr << "\n";
   }
}


int main(){
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;

    
    CreateEmployeeContainer (data1);
    CreateEmployeePointer (data2);
    CreateEmployeeSmartPointer (data3);

    /*
        2) std::find_if
            std::find_if returns "iterator to the FIRST MATCHING OBJECT"
            If match is not found, find_if returns end iterator
    */

   // we have written this all but let make our code clear by this all into 1 function named as search
//    auto itr = std::find_if(
//     data1.begin(),
//     data1.end(),
//     [](const Employee& emp){ return emp.designation() = "Trainer";}
//    );
//    if(itr == data1.end()){
//         std::cerr << "Object not found\n";
//    }
//    else{
//     std::cout << "Object found" << *itr << "\n";
//    }

}
