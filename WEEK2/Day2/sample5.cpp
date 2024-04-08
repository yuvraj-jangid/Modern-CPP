// /*
//     triggers app
//     f1------------------> f2(2 integers will be created)
//                         |
//                         |
//                         |
//                         predicate to filter the data
// */

// /*  *******REMEMBER********
//     lambda_fn is not a function it is an object which has its memory in stack
// */

// void f2(int n1, int n2){
//     /*
//         A lambda can capture data from its enclosing function without 
//         explicit passing
//     */
//     // auto lambda_fn = [](int n1, int n2){ return n1+n2;};
//     // lambda_fn(10,20); 
//     auto lambda_fn = [ & ](){return n1+n2;}; // this & in [] is called capture closure
//     lambda_fn(); 
// }

// void f1(){
//     int n1 = 10;
//     int n2 = 20;
//     f2(n1, n2);
// }

// int main(){
//     f1();
// }

#include <iostream>
#include <functional>

std::function<int()> f2(int n1, int n2) {
    auto lambda_fn = [ & ](){int val = 99; return n1+n2+10+20+val;}; 
    lambda_fn();
    return lambda_fn;
}

void f1(){
    int n1 = 10;
    int n2 = 20;
    std::function<int()> modified_function = f2(n1, n2);
    std::cout << modified_function() << "\n";
}

int main(){
    f1();
}


/*
    void Magic(){
        int n1 = 10, n2 = 20;
        
        example 1 : all data values from "enclosing function" are accessible inside f1
        auto f1 = [&]() {return n1 + n2;}

        example 2 : selected data values capture by copy 
        auto f1 = [n1]() {return n1 + n2;}
        // only n1 is accessible by copy, n2 is not. we get error

        example 3 : selected data values capture by copy
        auto f1 = [n1, n2]() {return n1 + n2;}
        // only n1 and n2 are accessible by copy

        example 4 : all data values capture by references
        auto f1 = [&n1, &n2]() {return n1 + n2;}
        // both are accessible as references

        example 5 : all data values from "enclosing function" are accessible inside f1
        auto f1 = [&]() {return n1 + n2;}
    }
*/


void trick() {
    int n1 = 100;
    // all copies not modifible unless you use mutable
    auto f1 = [=]  () mutable { // like rust you have to mark as mutable
        n1 = 99;
    };
}
// output will be 100 not 99 because it is call by value and it will be not changed outside the scope
