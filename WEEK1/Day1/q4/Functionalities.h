#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Car.h"
#include <array>

using contain = std::array<Car*, 3>;

/*
    college student : CreateObjects takes one vector of Car pointers to store of objects of child type
    tcs level : CreateObjects accepts one container of type vector in which we will do upcasting to store objects of child type
    professional engineer of CPP :
     CreateObjects is a top-level(global) function which takes one argument of type std::vector to Car pointers BY REFERENCE. This function returns void. 
*/
// std::vector<Car*> data :- CALL BY VALUE 
// std::vector<Car*>& data :- CALL BY REFERENCE






void CreateObjects(contain& data);

void DeleteObjects(contain& data);
#endif // FUNCTIONALITIES_H
