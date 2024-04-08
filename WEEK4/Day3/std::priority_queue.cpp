#include <iostream>
#include <queue>
#include <vector>
#include "Functionalities.h"

struct Less_Comparator
{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main() {
    std::vector<int> data {11, 10, 22, 7, 9, 15, 27, 18};

    std::priority_queue<int, std::vector<int>, Less_Comparator> pq (data.begin(), data.end());

    while(!pq.empty()){
        std::cout << "Popping: " << pq.top() << '\n';
        pq.pop();
    }

    // example 2 : integer stored in priority queue. Comparator is a built-in FUNCTOR  OBJECT [std::greater<int>]
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq2 (data.begin(), data.end());



    // example 3: using lambda for comparator. Storing employees in priority queue

    auto comp = [](const Employee& e1, const Employee& e2){
        return e1.expYears() < e2.expYears();
    };

    EmployeeContainer employees; // empty container 
    CreateEmployees(employees); // fill the container

    // Note: if using lambda as comparator, also lambda object as a parameter to the constructor of priority_queue

    std::priority_queue<Employee, std::vector<Employee>, decltype(comp) > pq3(
        
        employees.begin(),
        employees.end(),
        comp // last parameter is 
        );
}
