/*
    system which accepts data values and "logic". This logic will be applied on every single data value received and
    corresponding ouput will be shown

    fn(data, logic)
*/

#include <iostream>
#include <functional> //support for functional programming! in modern c++

// yaha se square function hata ke main mein daal diya usko as a lambda function


void Cube(int number){
    std::cout << "Cube of: " << number << " is: " << number*number*number;
}

// operation is a higher fucntion
// a higher order function either
// accepts or returns (or both) another function
void Operation(const std::vector<int>& data, std::function<void(int)>fn){ //function wrapper 
    for (int val : data)
    {
        fn(val);
    }
    
}

int main(){
    // fn pointer

    std::vector<int> data {10, 20, 30, 40, 50};
    Operation(
        data,
        
        //lambda function  i.e. an anonymous function with no name
        // [](int number)->void { // lambda function written by [] //it's okay wjen we don't write -> void 
        [](int number) {
        std::cout << "Square of: " << number << " is: " << number*number;
        }

        );

}
