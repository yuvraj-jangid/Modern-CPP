#include "Functionalities.h"

std::mutex mt;

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<DieselCar>("Porsche", "tycan", 12.0f, 900.0f));
    data.push_back(std::make_shared<Electric>("Penninferina", "battista", 40.0f, 1900.0f));
    data.push_back(std::make_shared<DieselCar>("TATA", "Tigor", 40.0f, 1900.0f));
    data.push_back(std::make_shared<Electric>("TATA", "nexon", 40.0f, 1900.0f));
    data.push_back(std::make_shared<DieselCar>("MG", "hector", 40.0f, 1900.0f));

}

void Common(Container &data1)
{
    for(Vtype v: data1)
   { std::visit(
        [](auto&& val){
            std::lock_guard<std::mutex> lk(mt);
            std::cout<<"Brand is: "<<val->brand()<<"\n"<<"Model is: "<<val->model()<<'\n'<< std::endl;
        },v
    );}
   
}

void UnCommon(Container &data2)
{
   for(Vtype v :data2){
    if(std::holds_alternative<DieselCarPtr>(v)){
        DieselCarPtr ptr = std::get<0>(v);
        std::lock_guard<std::mutex> lk(mt);
        std::cout<<"Mileage is: "<< ptr->mileage()<< "\n";
        std::cout<<"Horsepower is: "<<ptr->horsepower()<<"\n" << std::endl;

    }
   }
}
