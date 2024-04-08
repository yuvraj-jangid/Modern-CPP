#include "Employee.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

int main() {
    Magic(sptr);

    std::weak_ptr<Employee> wkptr = sptr;

    if(wkptr.lock()){
        std::cout << "Owner zinda hai!\n";
    } else {
        std::cout << "Owner toh gya!\n"
    }

    sptr.reset();
    std::this_thread::sleep_for(std::chrono::seconds(100));

    if(wkptr.lock()) {
        std::cout << "Owner zinda hai!\n";
    } else {
        std::cout << "Owner toh gaya!\n";
    }
}
