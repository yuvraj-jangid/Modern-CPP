/*
    Hashtable
    Key is integer (employee ID)
    value is Employee object on stack
*/

#include <iostream>
#include <unordered_map>
#include "Employee.h"

template<typename K, typename V>
void Display(const std::unordered_map<K,V>& mapData){
    for(auto [key, value] : mapData){
        std::cout << key << "\t" << value <<"\n";
    }
}

template<typename K, typename V>
void CreateObjects(const std::unordered_map<K,V>& mapData) {
    mapData.emplace(101, Employee("Harshit", 8098.0f, "Trainer", 10) );
    mapData.emplace(102, Employee("Mahesh", 8088.0f, "Developer", 7) );
}

int main() {
    std::unordered_map<int, Employee> mapData;
    CreateObjects<int, Employee>(mapData);
    Display<int, Employee>(mapData);
}
