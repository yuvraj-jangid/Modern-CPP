/*
    Objective : Create an adaptor which takes
    1) A callable of the following signature
        Input : int and int
        Output void
    2) integer number n1
    3) integer number n2

    The adaptor must apply/map the callable on the 2) and 3) integers
*/

#include <iostream>
#include <functional>

/*
    Adaptor is a higher order function
    A function that accepts a function as a second or third parameter is known as higher order function

    a function wrapper for all functions that have the following signature
        i) int, int input parameters
        ii) void as return type

    and 2 integers by value
*/

void Adaptor(std::function<void(int, int)> fn, int n1, int n2)
{
    fn(n1, n2);
}

void f1(int n1, int n2) {std::cout << n1 * 100 * n2;}

int main()
{
    Adaptor(
        [](int n1, int n2)
        { std::cout << n1 * n2 << "\n"; },
        10, 20
        );
    Adaptor(
        [](int n1, int n2)
        { std::cout << n1 - n2 << "\n"; },
        20, 10
        );
    Adaptor(
        f1,
        10,
        24
    );
}
