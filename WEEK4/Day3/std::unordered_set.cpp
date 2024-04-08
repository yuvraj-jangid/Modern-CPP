/*
    key and value both are same in unordered set 

    You cannot add the same key in unordered map and unordered set
*/

#include <unordered_set>
#include <iostream>

int main() { 
    std::unordered_set<int>s1 {11, 12, 11, 13, 11, 14};

    auto pair = s1.insert(11);

    if  (pair.second) {
        std::cout << "Eelement Added!\n";
    }

    else {
        std::cout << "Element not Added\n";
    }
}

/* Frawback is : if we want to take out data it will be in an unorderd format and it is based on Hash table

    if you want ordered 

    you can use set because it is in a ordered way and it is based on AVL tree
*/
