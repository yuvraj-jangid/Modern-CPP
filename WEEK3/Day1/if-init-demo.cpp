// if initializer syntax it is only available from cpp17

#include <iostream>
#include <vector>

std::vector<int> FindOddNumber(std::vector<int>& data){
    std::vector<int> result;

    for(int val : data){
        if(val % 2 != 0){
            result.push_back(val);
        }
    }

    return result;
}

int main(){
    std::vector<int> data {10,10,10,10,10}; // the function may return empty conatiner 
    if (std::vector<int> result = FindOddNumber(data); !result.empty())
    {
        /* code */
    }
    
}
