#include <iostream>
#include <memory> //yaha se shared pointer lenge

class Example1
{
private:
    std::string _name;
    int _id;
public:
    Example1(int id, std::string name) : _id{id}, _name{name} {}
    ~Example1() {}
};

void Dummy() {
    std::shared_ptr<Example1> sptr {std::make_shared<Example1>(10, "Yuvraj")};

    int n1 {0};

    std::cin >> n1;

    std::cout << 10/n1;

}





/*
    smart pointers in modern cpp

    1) unique pointer 
    2) shared pointer 
    3) weak pointers (token which can convert to shared pointer)
*/
