#ifndef CHARGINGUNIT_H
#define CHARGINGUNIT_H

#include<iostream>
#include<vector>
#include<array>
#include<variant>

using DischargedUnits = std::variant<std::vector<float>,std::array<float,5>>;

class ChargingUnit
{
private:
    std::string _id;
    float _rating_kw;
    DischargedUnits _last5_discharged_units;
    float _capacity;
    float _cost_per_kw;
public:
    ChargingUnit() = delete;

    ChargingUnit(const ChargingUnit&) = delete;

    ChargingUnit& operator=(const ChargingUnit&) = delete;

    ChargingUnit(ChargingUnit&&) = delete;

    ChargingUnit& operator=(ChargingUnit&&) = delete;

    ~ChargingUnit() = default; 

    ChargingUnit(std::string id,float rating_kw,DischargedUnits last5_discharged_units,float capacity,float cost_per_kw);

    std::string id() const { return _id; }

    float ratingKw() const { return _rating_kw; }

    DischargedUnits last5DischargedUnits() const { return _last5_discharged_units; }

    float capacity() const { return _capacity; }

    float costPerKw() const { return _cost_per_kw; }

    friend std::ostream &operator<<(std::ostream &os, const ChargingUnit &rhs);
    
};

#endif // CHARGINGUNIT_H
