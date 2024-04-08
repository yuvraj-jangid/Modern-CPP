/*
    Objective : Design an adaptor to accept
        a vector of integers
        Use the predicate to print data from the vector
*/

// A predicate is a function that return TRUE OR FALSE that takes one value as a parameter

#include <iostream>
#include <functional>
#include <vector>

void Adaptor(std::function<bool(int)> predicate, const std::vector<int>& data){
    for(int val : data){
        if(predicate(val)) {std::cout << val;}
    }
}

int main(){
    Adaptor(
        [](int number) {return number % 5 == 0;},
        std::vector<int> {10, 20, 46, 30, 26}
    );

    Adaptor(
        [](int number) {return number % 5 == 0 && number % 3 == 0;},
        std::vector<int> {10, 20, 46, 30, 26}
    );

    Adaptor(
        [](int number) {return number / 2 == 0;},
        std::vector<int> {10, 20, 46, 30, 26}
    );


}
