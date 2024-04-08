#include <iostream>

// -Werror and -Wextra ---> we should always use this so check all the exceptions and errors 
//  after using these all the warnings will behave like errors 

class Dummy
{
private:
    /* data */
public:
    Dummy() noexcept {}
    // void Display() noexcept{std::cout<<"HELLO"; throw 1;} // so here throw 1 will lead to an warning but after writing -Werror and -Wextra it is an error
    void Display() noexcept{std::cout<<"HELLO";}
    ~Dummy() {}
};

int main(){
    Dummy d;
    d.show;

    return 0;
}
