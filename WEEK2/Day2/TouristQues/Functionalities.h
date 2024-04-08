#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "TouristVehicle.h"
#include <list> // we have to use list not vector as given in the question
//include all the exceptions
#include "EmptyContainer.h"
#include "NegativeValue.h"
#include "Oversized.h"
#include "WrongType.h"

using TouristVehiclePtr = std::shared_ptr<TouristVehicle>;
using Container = std::list<TouristVehiclePtr>;

void CreateObjects(Container& data);

Container PermitTypeCondition(const Container& data, int N); //humne const kiya kyunki hum chahte hai ye rad only rhe or ye change naa ho 
// humne list banayi aur touristvehicleptr return krna hai container bana ke 

float AvgPerType(const Container& data, int N);

unsigned long MaxPerBookingCharge(const Container& data);

Container FirstNinstances(const Container& data, int N);


#endif // FUNCTIONALITIES_H
