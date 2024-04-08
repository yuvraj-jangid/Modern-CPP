#include "DieselCar.h"
std::ostream &operator<<(std::ostream &os, const DieselCar &rhs) {
    os << "m_brand: " << rhs.m_brand
       << " m_model: " << rhs.m_model
       << " m_mileage: " << rhs.m_mileage
       << " m_horsePower: " << rhs.m_horsePower;
    return os;
}

DieselCar::DieselCar(std::string brand, std::string model, float mileage, float horsepower)
:m_brand{brand}, m_model{model}, m_mileage{mileage}, m_horsePower{horsepower}
{
}
