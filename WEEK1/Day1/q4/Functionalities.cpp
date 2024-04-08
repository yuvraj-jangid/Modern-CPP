#include "Functionalities.h"
#include "ElectricCar.h"

void CreateObjects(contain &data)
{
    // data.push_back(

    //     new ElectricCar("NexonEV", 80, 150, 1870000.90f, 33, 2, 300, 600, 320));

    // data.push_back(
    //     new ElectricCar("XUV400", 70, 140, 1670000.90f, 31, 2, 280, 600, 320));
    data[0] = new ElectricCar("NexonEV", 80, 150, 1870000.90f, 33, 2, 300, 600, 320);
    data[1] = new ElectricCar("NexonEV", 80, 150, 1870000.90f, 33, 2, 300, 600, 320);
}

void DeleteObjects(contain &data)
{
        for(int i=0; i<=1; i++){
            delete data[i];
        }

    // modern cpp 
    // for each loop
    // for (auto p : data)
    // {
    //     delete p;
    // }
}

