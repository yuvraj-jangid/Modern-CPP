// bind 

/*
    1) We cannot massively change code
    after it is deployed for client

    2) Sometimes API parameters need to be 
    fixed at certain value
*/

#include <iostream>
#include <functional>
#include <list>
#include <cstring>

void Formula (const int x, const int y, const int z) {
    std::cout << "Answer is: " << ((x+y) - z) << "\n";
}

void Magic(const std::list<int>& data, int n) {

    for(int val: data){
        n--;
        if(n == 0){
            std::cout << val << "\n";
            break;
        }
    }
}

int main() {
    Formula(10, 20, 30); //x=10, y=20, z=30

    //set the value of x in formula to 100 fixed forever!

    auto binded_formula = std::bind( &Formula, 100, std::placeholders::_1, std::placeholders::_2); // placeholder means here user will enter i am keeping this empty 
    //100 fix krdiya and 1 and 2 pe input de sakta hai user
    binded_formula(30, 40); // x= 100, y = 30, z = 40

    // swap the values using bind 
    auto binded_formula = std::bind(&Magic, std::placeholders::_2, std::placeholders::_1);

    auto binded_strcpy = std::bind(&strcpy, std::placeholders::_2, std::placeholders::_1);
    
    
    
    

    auto fn = [](int number, int factor) {std::cout << number * factor;}; // lamda function

    //a lambda is an object. using & on lamda means taking address of object.
    // Don't use & sign with lambda in bind!
    auto binded_lamdba_fn = std::bind(fn, std::placeholders::_1, 40); // yaha pe humne factor ko 40 set kr diya 

    /*
        void Magic(const int n1, std::string& name);

        std::function <void (const int, std::string&)> fn = &Magic;

        we use auto for lambda and binded because we don't know the type of function it is unpredictable 
    */

    


}


// ashish.rawat@kpit.com
