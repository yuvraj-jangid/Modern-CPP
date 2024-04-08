#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data[0] = new Car(
        "c101",
        779000.0f,
        "Dzire",
        new Engine (
            300,
            110.0f
        ),
        CarType::SEDAN
    );

    data[1] = new Car(
        "c102",
        1479000.0f,
        "Honda City",
        new Engine (
            400,
            130.0f
        ),
        CarType::HATCHBACK
    );

    data[2] = new Car(
        "c103",
        619000.0f,
        "Safari",
        new Engine (
            600,
            150.0f
        ),
        CarType::SUV
    );

}

void DeleteObjects(Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    for (Car* c : data){
        delete c->engine();
        delete c;
    }
}

int TotalHorsepower(const Container &data)
{
    if (data.empty()){
        throw IdNotFoundException(std::future_errc::broken_promise,"Id not found");
    }
    float total = 0.0f;
    for(Car* c: data){
        total += c->engine()->horsepower();
    }
    return total;
}

bool IsContainerAllCarAbove700000(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }
    for(Car* c : data){
        if(c->price()<=700000.0f){
            return false;
        }
    }
    return true;
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }
    float min_price = data[0]->price();
    Engine* e = data[0]->engine();

    for(Car* c : data){
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
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    float total_value = 0.0f;
    for(Car* c : data){
        total_value += c->engine()->torque();
    }
    return total_value / data.size();
}

std::string FindCarModelById(const Container &data, const std::string carId)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }
    std::string id="";
    for (Car* c : data){
        if(c->id() == carId){
            return c->model();
        }
    }
    if(id=="") throw IdNotFoundException(std::future_errc::broken_promise,"Id not found");
    return id;
}
