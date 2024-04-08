/*
    Processor : It is a hardware device based on SILICON (AT LEAST TILL TODAY) which executed instructions given
    e.g. : intel i5 12th gen 1230u

    Core : It is a section of processor which is capable or executing ONE WHOLE PROCESS

    SINGLE THREAD, SINGLE PROCESS, SYNCHRONUS PROGRAMS! (we have written till now)
*/

/*
Delays : IO delay, CPU-BOUND DELAY!
*/

#include <iostream>
#include <array>
#include <thread>

void Square(std::array<int, 5>& data){
    for(int number : data){
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Square of: " << number << " is: " << number*number << "\n";
    }
}


void Cube(std::array<int, 5>& data){
    for(int number : data){
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Cube of: " << number << " is: " << number*number << "\n";
    }
}


int main(){
    std::array<int, 5> arr{1,2,3,4,5};

    Square(arr);
    Cube(arr);
    
}
