// variadic templates 

#include <iostream>

/*
    add is a function that takes 2 parameters of type "int"
    It uses them as operands for binary + operator and returns 
    the result of + operator applied on these operands
*/

template <typename T>
T add(T n1){
    return n1;
}

template <typename T, typename... Remaining>
T add(T n1, Remaining... args) {
    return n1 + add(args...);
}

int main() {
    std::cout << add<int>(10, 20) << "\n";
    std::cout << add<float>(10.21f, 10.23f) << "\n";
    std::cout << add<int>(10) << "\n";
    std::cout << add<int>(10,20,30,40,50,60,70) << "\n";
}
