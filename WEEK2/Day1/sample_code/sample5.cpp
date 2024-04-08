#include <iostream>

/*

*/

void Magic(int& argref) {

}

int main(){
    int n1 = 99;
    int& ref = n1; // creating a reference 
    Magic(n1); // pass by reference
/*
     a reference DOES NOT EXIST ANYWHERE IN MEMORY 
     ALTERNATE NAME FOR SOMETHING DOES NOT ACQUIRE ANY MEMORY
*/
    // int& arr[] = {ref}; //it will give an error

}

/*
    Fn(int a);
    Fn(10);     int a = 10;


    previously;
            A pointer when stored internally in an object 
            created representation of a pointer (Smart Pointer)

            A reference stored in an object internally
            creates representation of a reference called reference_wrapper
*/
