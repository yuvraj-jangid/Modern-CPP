#include "Employee.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

/******NOTE******
     we cannot pass by value in unique pointer 

     unique_pointer // resource ka ek hi owner ho sakta h isme
 */

std::mutex mt;
bool allThreadsDone = false; // if init ke liye liya hai 

void ChangeName(std::unique_ptr<Employee>& owner2) { // call by reference & krna padega
    owner2->setName("Harshit Shukla");
    std::cout << *owner2 << "\n";
}


void UpdateSalary(std::unique_ptr<Employee>& owner3) { // call by reference & krna padega
    owner3->setSalary(753320035.0f);
    std::cout << *owner3 << "\n";
}

int main(){
    std::unique_ptr<Employee> ptr = std::make_unique<Employee>("Harshit", 23556.0f, "Trainer", 10);
    // std::cout << *ptr << "\n";

// let's try with thread also 
    std::thread t1 (&ChangeName, ptr);
    std::thread t2 (&UpdateSalary, ptr);

    if(std::lock_guard<std::mutex> lg(mt); !allThreadsDone ){
        std::cout << *ptr << "\n";
    }

    t1.join();
    t2.join();

    allThreadsDone = true;
}
