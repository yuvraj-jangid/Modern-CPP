#include <iostream>
#include <functional>

class Action
{
private:
    int m_id;
    /* data */
public:
    Action() {}
    ~Action() {}

    void Operation(int number) {
        std::cout << m_id * number;
    }
};

int main(){
    Action a1;
    auto binded_operation = std::bind(&Action::Operation, &a1, 40); 

    binded_operation(); // a1.operation(40);
}
