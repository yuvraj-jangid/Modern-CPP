#include "Car.h"
#include "CarType.h"
/*
    constructor delegation : use multiple constrcuction OF THE SAME CLASS together to make the object 
*/


Car::Car(std::string id, std::string model, std::shared_ptr<Engine> engine,CarType ctype)
    : _id{id}, _model{model}, _engine{engine}, _type{ctype}
{
}

// WE CANNOT USE DELEGATED CONSTRCUTORS AND MEMBER LIST INITIALIZATION 

Car::Car(std::string id, float price, std::string model, std::shared_ptr<Engine> engine, CarType ctype)
    : Car(id, model, engine, ctype)
{
    _price = price;
}


std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _model: " << rhs._model
       << " _engine: " << rhs._engine;
    return os;
}




