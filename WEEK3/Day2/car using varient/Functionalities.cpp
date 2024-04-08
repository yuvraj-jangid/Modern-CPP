#include "Functionalities.h"

void CreateObjects(Container &data, FnContainer& fn)
{
    data.push_back(std::make_shared<DieselCar>("Porsche", "Carrera", 18.25, 662.0f));
    data.push_back(std::make_shared<ElectricCar>("Pininfarina", "Battista", 450.5, 1900.0f));

    fn.push_back(Common);
    fn.push_back(UnCommon);
}

//using thread 
void MakingThreadContainer(ThreadContainer &th, Container &data, FnContainer &fn)
{
    for(Fntype it : fn){
        th.push_back(std::thread(it,std::ref(data)));
    }
}

void JoinThread(ThreadContainer &th)
{
    for(std::thread &it : th){//thread cannot be copy that why we use & with "it"
        if(it.joinable()){
            it.join();
        }
    }
}

// using lambda function 
Fntype uv =[](const Container &data){
    if(data.size() == 0){
        throw EmptyException("The given container is Empty!");
    }

    for(VType v : data){
        std::visit(
            [](auto&& val){
                std::cout << "Car Brand is: " << val->brand() << "\n"; 
                std::cout << "Car Model is: " << val->model() << "\n"; 
            }, v
        );
    }
};

void Common(const Container &data)
{
    
    if(data.size() == 0){
        throw EmptyException("The given container is Empty!");
    }

    for(VType v : data){
        std::visit(
            [](auto&& val){
                std::cout << "Car Brand is: " << val->brand() << "\n"; 
                std::cout << "Car Model is: " << val->model() << "\n"; 
            }, v
        );

}

}

void UnCommon(const Container &data)
{
    if(data.size() == 0){
        throw EmptyException("The given container is Empty!");
    }
    
    for(VType v : data){
        if(std::holds_alternative<ElectricCarPtr>(v)){
            ElectricCarPtr range = std::get<1>(v);
            std::cout << "Range is: " << range->range() << "\n";
        }
    }
}
