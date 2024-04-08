/*
    create an array of 3 threads

        - thread 1 should calculate square of each number in the array
        and store in a result array (position 1 to 5)
        - thread 1 should calculate cube of each number in the array
        and store in a result array (position 6 to 10)
        - thread 1 should calculate factorial of each number in the array
        and store in a result array (position 11 to 15)

        Assumption : Numbers in the input array will be between 1 to 10
*/

#include <iostream>
#include <array>
#include <thread>
#include <mutex>
#include <functional>

using FnType = std::function<void(int)>;
using FnContainer = std::array<FnType, 3>;
using InputDataContainer = std::array<int, 5>;
using ResultContainer = std::array<int, 15>;
using ThreadArray = std::array<std::thread, 5>;

void StoreFunctionInContainer(FnContainer& fns, InputDataContainer& data, ResultContainer& result) {

    fns[0] = [&](int k){
        for(int number : data){
            result[k++] = number*number;
        }
    };

    fns[1] = [&](int k){
        for(int number : data){
            result[k++] = number*number*number;
        }
    };

    fns[2] = [&](int k){
        for(int number : data){
            if (number == 1){
                result[k++] = 1;
            } else{
                int amount = 1;
                for(int k = 2; k <= number; k++){
                    amount *=1;
                }
                result[k++] = amount;
            }
        }
    };
}


void MapFunctionToThread(FnContainer& fns, ThreadArray& thArr){
    int position[3] = {0,5,10};
    for(int i = 0; i< thArr.size(); i++){
        thArr[i] = std::thread(fns[i], position[i]); //i = position[k]
    }
}

void JoinThreads(ThreadArray& thArr){
    for(std::thread& t : thArr){
        if(t.joinable()){
            t.join();
        }
    }
}

void Display(const ResultContainer& result){
    for(const int val : result){
        std::cout << val << "\n";
    }
}

int main() {
    //input array
    std::array<int, 5> data {1,2,3,4,5};
    //result array
    std::array<int, 15> result;
    int 
}
