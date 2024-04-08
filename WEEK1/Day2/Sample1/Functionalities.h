#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H


#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

#include <array> //STL
#include "Car.h"

using Container = std::array<Car*, 3>;

void CreateObjects(Container& data);

void DeleteObjects(Container& data);

/*
    input : Container
    output : int
*/

int TotalHorsepower(const Container& data);

/*
    Is this condition true or false : All cars in the conatiner have a price above 700000
*/

bool IsContainerAllCarAbove700000(const Container& data);

/*
    return the _engine pointer of the car whose price is lowest
    If multiple Car instances have the same minimum, consider first minimum found
*/

Engine* EnginePointerToMinPriceCar(const Container& data);

/*
    find the average torque for engines in the Car container
*/

float AverageEngineTorque(const Container& data);

/*
    A function to print the model name of the Car whose _id is passed as a parameter
*/

std::string FindCarModelById(const Container& data, const std::string carId);


#endif // FUNCTIONALITIES_H
