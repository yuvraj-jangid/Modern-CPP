#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data[0] = std::make_shared <Car>(
        "c101",
        779000.0f,
        "Dzire",
        std::make_shared <Engine> (
            300,
            110.0f
        ),
        CarType::SEDAN
    );

    data[1] = std::make_shared <Car>(
        "c102",
        1479000.0f,
        "Honda City",
        std::make_shared <Engine> (
            400,
            130.0f
        ),
        CarType::HATCHBACK
    );

    data[2] = std::make_shared <Car>(
        "c103",
        619000.0f,
        "Safari",
        std::make_shared <Engine> (
            600,
            150.0f
        ),
        CarType::SUV
    );

}

void DeleteObjects(Container &data)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    for (CarPointer c : data){
        delete c->engine();
        
    }
}

int TotalHorsepower(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }
    float total = 0.0f;
    for(CarPointer c: data){
        total += c->engine()->horsepower();
    }
    return total;
}

bool IsContainerAllCarAbove700000(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }
    for(CarPointer c : data){
        if(c->price()<=700000.0f){
            return false;
        }
    }
    return true;
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }
    float min_price = data[0]->price();
    Engine* e = data[0]->engine();

    for(CarPointer c : data){
        if(c->price() < min_price){
            min_price = c->price();
            e = c->engine();
        }
    }

    return e;
}

float AverageEngineTorque(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    float total_value = 0.0f;
    for(CarPointer c : data){
        total_value += c->engine()->torque();
    }
    return total_value / data.size();
}

std::string FindCarModelById(const Container &data, const std::string carId)
{
    if (data.empty()){
        throw EmptyContainerException("Data is empty");
    }
    for (CarPointer c : data){
        if(c->id() == carId){
            return c->model();
        }
    }

    throw IdNotFoundException("Id not found");
}
