/*
    SMART POINTERS : They are wrappers around raw pointers to allow 
    better memory management using RAII deisgn pattern

        1) shared_pointer // isme jitne chahiye utne owner bana sakte hai 
        2) unique_pointer // resource ka ek hi owner ho sakta h isme
        3) weak_pointer : stalker pointer[shared pointer----> token]
*/

#include "Employee.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex mt;
bool allThreadsDone = false; // if init ke liye liya hai 

void ChangeName(std::shared_ptr<Employee> owner2) {
    owner2->setName("Harshit Shukla");
    std::cout << *owner2 << "\n";
} // counter decrement


void UpdateSalary(std::shared_ptr<Employee> owner3) {
    owner3->setSalary(753320035.0f);
    std::cout << *owner3 << "\n";
}

int main(){
    std::shared_ptr<Employee> ptr = std::make_shared<Employee>("Harshit", 23556.0f, "Trainer", 10);
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
