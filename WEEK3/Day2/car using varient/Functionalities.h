#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DieselCar.h"
#include "ElectricCar.h"
#include "EmptyException.h"

#include <memory>
#include <variant>
#include <vector>
#include  <functional>
#include<thread>
#include<mutex>

using DieselCarPtr = std::shared_ptr<DieselCar>;
using ElectricCarPtr = std::shared_ptr<ElectricCar>;

using VType = std::variant<DieselCarPtr, ElectricCarPtr>;
using Container = std::vector<VType>;

using Fntype = std::function<void (const Container&)>; // Function wrapper
using FnContainer = std::vector<Fntype>;
using ThreadContainer = std::vector<std::thread>;



extern Fntype uv; 

void CreateObjects(Container& data, FnContainer& fn) ;

void MakingThreadContainer(ThreadContainer& th, Container& data, FnContainer& fn);
void JoinThread(ThreadContainer& th);

void Common(const Container& data);
void UnCommon(const Container& data);


#endif // FUNCTIONALITIES_H
