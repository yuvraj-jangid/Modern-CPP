#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "DieselCar.h"
#include "Electric.h"
#include <variant>
#include <vector>
#include <thread>
#include <array>
#include <memory>
#include <mutex>

extern std::mutex mt;

using DieselCarPtr = std::shared_ptr<DieselCar>;
using ElectricPtr = std::shared_ptr<Electric>;

using Vtype = std::variant<DieselCarPtr, ElectricPtr>;

using Container = std::vector<Vtype>;

void CreateObjects(Container& data);

void Common(Container& data1);

void UnCommon(Container& data2);


#endif // FUNCTIONALITIES_H
