#include <iostream>
#include <array>
#include <functional>

/*
    Objective:
        Design an adaptor function that accepts a container of function wrappers and a conatiner of data values 
        Map each function on each iten in the data  container and the output 

        # All function must accept only an integer and return void
*/

using FnType = std::function<void(int)>;
using DataContainer = std::array<int, 5>;
using FnContainer = std::array<FnType, 5>;

void Adaptor(const FnContainer& fnc, DataContainer& dc){
    for(FnType f: fnc){
        for(DataContainer d: dc){
            f(dc);
        }
    }
}
