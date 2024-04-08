/*
    system which accepts data values and "logic". This logic will be applied on every single data value received and
    corresponding ouput will be shown

    fn(data, logic)
*/

#include <iostream>
#include <functional> //support for functional programming! in modern c++

void Square(int number){
    std::cout << "Square of: " << number << " is: " << number*number;
}


void Cube(int number){
    std::cout << "Cube of: " << number << " is: " << number*number*number;
}

// operation is a higher fucntion
// a higher order function either
// accepts or returns (or both) another function
void Operation(int* arr, int size, std::function<void(int)>){ //function wrapper 
    for (int i = 0; i < size; i++)
    {
        (arr[i]);
    }
    
}

int main(){
    // fn pointer
    // void (*ptr1)(int) = Square;
    // void (*ptr1)(int) = Cube;

    int arr[5] = {10, 20, 30, 40, 50};
    Operation(arr, 5, Square);

}






/*
    Higher order functions!
    Anonymous functions 
    functional programming paradigm
    no state
    immutable data
    currying 
    First-class functions
*/
