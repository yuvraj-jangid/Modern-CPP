#include <iostream>
#include <functional>

/*
    The actual data type of lambda is unknown 
*/



void Magic( std::function<void(int)> fn){
    fn(10); // this will call the lambda function inside the wrapper
}

int main(){
    auto f1 = [] (int number) { std::cout << number * 10;};
    f1 (10); //like a function, overloaded () operators

    Magic(
        [] (int number) { std::cout << number * 10;}
    );
} 
