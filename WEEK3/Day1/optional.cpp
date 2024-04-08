/*
    developer part : what is the API? what is the design? what is the corner case?

    scenario 1 : My input has atleast 1 value
                Some of the values in the input are odd

    scenario 2 : My input has atleast 1 value
                None of the values in the input are odd

    scenario 3 : Input is empty
                - NOTHING WILL WORK! [Not my concern Input invalid Exception]

    My function may or may not be able to return SOMETHING VALID!
    std::optional : indicates an algebric datatype that may
                    - either conatin a valid value 
                    - or a symbol indicating "ABSENCE OF INFORMATION"

********optional is used when you dont know that there will may or may not be output**********

*/
#include <iostream>
#include <vector>
#include <optional> // header file

std::optional<std::vector<int> >FindOddNumber(std::vector<int>& data){

    if(data.empty()){
        throw std::runtime_error("problem");
    }
    std::vector<int> result;

    for(int val : data){
        if(val % 2 != 0){
            result.push_back(val);
        }
    }
    if(result.empty()){
        return std::nullopt; // symbol to indicate no information
    }
    
    return result; 
}

/*
    caller : the user who invokes or calls the functionality or access the API
*/

int main(){
    std::vector<int> data {10,10,10,10,10}; // the function may return empty conatiner 
    if (std::vector<int> result = FindOddNumber(data); !result.empty())
    {
        std::cout << "Mein hi pagal hu, nahi nahi mein pagal!"
    }
    
}
