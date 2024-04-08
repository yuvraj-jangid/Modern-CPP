#include <array>
#include <iostream>
#include <unordered_map>

int main(){

    std::unordered_map<int, std::string> map{
        std::make_pair<int, std::string>(101, "Harshit"),
        std::make_pair<int, std::string>(102, "Rohan")
    };

    std::array<int, 2> data {101, 90000};
    auto [empId, empsalary] = data;

    for(auto& [k,v] : map){
        std::cout << "Key is: " << k << "value is: " << v << "\n";
    }
}
