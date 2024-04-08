#include <iostream>
#include <vector>

/*
    numbers passed to magic must be temporary value or moved values
    capture parameter by rvalue reference 
*/

void Magic(std::vector<int>&& data){ // && is move

}

int main(){
    std::vector<int> value {10, 20, 30, 40, 50};
    Magic(std::move(value));

    // std::cout << value.size(); // hum log magic ko access dene ke baad main mein access krke dekh rhe hai ab kuch bhi error aa sakta hai
}

/*
    We create vector in main (scope in main)
    HEAP
    [10, 20, 30, 40, 50 |     |     |     |     ]
    ^                 ^                         ^
    |                 |                         |
    |                 |                         |
    [ 0x100  | 0x116  |        0x132            ]
    <------------Main variable------------------>
    <--------------24 Bytes--------------------->
*/

/*
    1) Praogram starts beacuse OS schedules the process
    2) Main fucntion is executed as a thread by the OS 
    3) Vector of interger values is created in the scope of main 
        3a) Heap allocation happens and vector gets space on heap
        3b) Pointers to start, end and capacity are recorded in the vector object "value" in main
    4)Magic(std::move(value))
        4a) std::move(value) : It converts lvalue into rvalue(tells the compiler "value" vector can be prepared for move)
        4b) Now vector value is treated as an rvalue...so Magic(std::move(value)) becomes Magic(std::vector<int> value {10, 20, 30, 40, 50})
*/

//  MOVE KRNE KE BAAD VARIABLE KO ACCESS NAHI KRNA CAHAHIYE 
