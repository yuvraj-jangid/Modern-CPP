#include <iostream>

class LambdaImplementation
{
private:
    int _number;
public:
    LambdaImplementation() = default;
    ~LambdaImplementation() = default;

    // function call () operator overloading 
    void operator() (int number) {
        std::cout << "Square of: " << number << " is: " << number*number << "\n";
    }
};

int main(){
    LambdaImplementation l1;
    l1(10); // operator() overloading called
}
