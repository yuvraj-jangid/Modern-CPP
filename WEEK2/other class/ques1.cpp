/*
    I want to design an adaptor that accepts
    a) A vector of integers 
    b) A logic that works on a single item at a time.
        This logic should "filter" the input data and only display value which satisfy the requirments of the logic
        eg. from a vector of 1,2,3,4,5 logic of "even numbers" should only display 2 and 4 
*/

#include <iostream>
#include <functional>

void Adaptor(const std::vector<int>& data, std::function<bool(int)> fn){
    std::vector<int> {1,2,3,4,5}, 
    [](int number) { return  number % 2! = 0;};
    
}
