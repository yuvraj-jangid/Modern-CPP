#include <Employee.h>

/*
    The middleman/ intermediate functions will have to designed
    to accept 0 or more argument (potentially infinite)

    2) lvalue binding  to rvalue situation is annoying!
*/

void Magic(int&& n1){ // 10 gets assigned to n1. now n1 is lvalue!
    //forwarding n1 to any function will now forward n1 as lvalue 
    //rather than rvalue
    //Demo(n1); //lvalue passed to rvalue reference 

}

template <typename T, typename

// Rule 1 : For regular, non template functions, T&& simply means Rvalue reference to T

// Rule 2 : For a template function of type T, T&& means forwarded references 
//         [Note : such a template function should ]
