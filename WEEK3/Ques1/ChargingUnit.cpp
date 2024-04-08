#include "ChargingUnit.h"

ChargingUnit::ChargingUnit(std::string id, float rating_kw, DischargedUnits last5_discharged_units, float capacity, float cost_per_kw)
 : _id(id),_rating_kw(rating_kw),_last5_discharged_units(last5_discharged_units),_capacity(capacity),_cost_per_kw(cost_per_kw)
{
    float sum=0;
    std::visit([&](auto&& x){
        for(auto &i:x){
            sum+=i;
        }
    },_last5_discharged_units);
    if(sum!=capacity){
        throw std::runtime_error("Invalid error");
    }

    /*IF capacity != to sum to last5 discharged throw error*/
}

std::ostream &operator<<(std::ostream &os, const ChargingUnit &rhs) {
    os << "_id: " << rhs._id
       << " _rating_kw: " << rhs._rating_kw
       << " _last5_discharged_units: ";
       std::visit([&](auto&& a){
        for(int i=0;i<5;i++){
            os<<a[i]<<" ";
        }
       },rhs._last5_discharged_units);
    os   << " _capacity: " << rhs._capacity
       << " _cost_per_kw: " << rhs._cost_per_kw;
    return os;
}

