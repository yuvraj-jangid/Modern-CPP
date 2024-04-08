#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include "ChargingUnit.h"
#include<vector>
#include<memory>
#include<array>

using Pointer = std::shared_ptr<ChargingUnit>;
using Container = std::vector<Pointer>;


/*
   Function for Creating the Object
*/
void CreateObject(Container& data);  

/*
    A function which return the gst amounts by giving data to it
*/
std::vector<float>  GstAmount(Container& data);

/*
    A function that returns cost_kw of two instances   
*/
std::array<float,2> CostPerKW(Container& data);

bool CheckValueOfRating(Container& data,float kw);

Container FindInstancerById(Container&data,std::vector<std::string> ids);

float AverageRatingKwByCostPerKw(Container&data,float cost_per_kw);

#endif // FUNCTIONALITIES_H
