#include <iostream>
#include <vector>

/*
    Magic is a function that accepts 1 stud vector of integers by value Magic returns void 
*/

void Magic(std::vector<int> data){
        
}

int main(){
    std::vector<int> v1 {10, 20, 30};
    Magic(std::vector<int> {1,2,3,4,5}); //vector is a rvalue // now data will be assigned to this vector and it will be accessed by Magic
    Magic(v1);
}
