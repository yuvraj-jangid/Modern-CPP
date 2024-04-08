#include<iostream>
#include "ChargingUnit.h"
#include<vector>
#include<memory>
#include "Functionalities.h"

using Pointer = std::shared_ptr<ChargingUnit>;
using Container = std::vector<Pointer>;

int main()
{
    Container data;

    try
    {
        CreateObject(data);   //Calling the Function for Creating the objects
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<float>r= GstAmount(data);
    for(auto&i:r){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    std::array<float,2> res = CostPerKW(data);
    for(int i;i<2;i++)
    {
        std::cout<<i<<std::endl;
    }

    std::cout<<CheckValueOfRating(data,3.0f)<<std::endl;

    std::vector<std::string>v{"ch101","ch202"};
    Container out= FindInstancerById(data,v);

    for(auto i:out)
    {
        std::cout<<*i<<std::endl;
    }

    std::cout<<AverageRatingKwByCostPerKw(data,2.5)<<std::endl;
}