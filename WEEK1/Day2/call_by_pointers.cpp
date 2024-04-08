#include <iostream>

void Magic(int* data){
    std::cout<<"Dereferencing data gives before modification: " << *data << "\n";
    std::cout<<"Content of data in Magic before modification is: " << data << "\n";
    std::cout<<"Address of value inside Magic is: " << &data << "\n";
    *data = 111;
    std::cout<<"Content of data in Magic after modification is: " << data << "\n";

}

int main(){
    int value = 100;
    std::cout<< "Value in main before modification is: " << value << "\n";
    std::cout<<"Address of value inside the Main is: " << &value << "\n";
    Magic(&value);
    std::cout<<"Value in Main after Magic call is: "<< value << "\n";
}
