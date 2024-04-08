#include "Copy_Elision_Employee.h"

Employee Magic() {
    Employee e1("Harshit", 78989.0f, "Trainer", 10);
    return e1;
}

int main() {
    Employee emp = Magic();
    std::cout << emp << "\n";
}
