#include <iostream>
#include <list>


void Magic(std::list<int>& data){

}

/*
    1)WeirdMagic can only be called by an rvalue
        -It means the user will never be able to make 2 copies of data: One in caller and one in callee(WeirdMagic)
*/


void WeirdMagic(std::list<int>&& data){  //double && is rvalue reference
    std::cout<< data.size()<<"\n";
}

int main(){
    std::list<int> l1 {1, 2, 3, 4, 5};
    Magic(l1); //call by lvalue reference
    WeirdMagic(std::list<int> {1,2,3,4,5}); // this value has no name like l1 so it is rvalue 

    // std::list<int> {1,2,3,4,5};
    // WeirdMagic(std::move(l1)); // here we are using move 
    // this data will be transferd to weird magic here move semantics is happening not actual data is moving only the ownership is moving
}

//move function can convert an l value to an r value 
// but here we already have r value so no need to use move functin we can do move semantics without move also
 