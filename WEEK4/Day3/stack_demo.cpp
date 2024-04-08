/*
    A situation where only one element needs to be accessed and it is the most recent item inserted into the container

    e.g. : A compiler executing functions calls 

    f1(){
        f2()
    }

    call stack 

    f2<----------recently added, top most entry. will be accessed first!

    f1<----------still pending

    Note : There are no iterators for stack you cannot apply for loop on stack
*/


#include <stack>
#include "Employee.h"
#include "Functionalities.h"

using Container = std::stack<Employee>;

int main() {
    Container s1; 
    s1.push(Employee("Harshit", 788790.0f, "Trainer", 10)); // push and pop 
}
