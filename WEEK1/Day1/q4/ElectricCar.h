#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H
#include "Car.h"
#include <ostream>

class ElectricCar : public Car
{
private:
    int _batter_capacity {0};
    float _time_to_charge {0.0f} ;
    float _motor_power {0.0f};
    float _max_power {0.0f};
    float _range {0.0f};
public:                 
    ElectricCar() = default; // default constructor enable
    ElectricCar(const ElectricCar&) = delete; //disabled copy constructor
    ElectricCar(ElectricCar&&) = delete; //disabled move constructor                            
    ElectricCar& operator = (const ElectricCar&) = delete; //deleted copy assignment operator
    ElectricCar& operator = (ElectricCar&&) = delete; //c++ brand new, deleted move assignment operator
    ~ElectricCar() = default; //destructor enabled
    
    float Drive() override; 
    void ShowElectricCarDetails();

    ElectricCar(std::string name, int acceleration, int top_speed, float price, int batter_capacity, float time_to_charge, float motor_power, float max_power, float range);

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);

    
};
#endif // ELECTRICElectricCar_H

