#include <iostream>

/*
    Accept infinite parameters
    add 1 parameter with remaining
*/


template <typename... T>
auto add(T... n1) {
    return (n1 + ...); // right associative operation
}


template <typename... A>
auto subtract(A... args) {
    return (args - ...); // (10 - (20 - (30 - 40)))
}

int main() {
    std::cout << add<int>(10, 20) << "\n";
    std::cout << add<float>(10.21f, 10.23f) << "\n";
    std::cout << add<int>(10) << "\n";
    std::cout << add<int>(10,20,30,40,50,60,70) << "\n";
}
