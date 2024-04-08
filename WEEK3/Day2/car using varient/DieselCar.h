#ifndef DIESELCAR_H
#define DIESELCAR_H

#include <iostream>

class DieselCar
{
private:
    std::string m_brand;
    std::string m_model;
    float m_mileage;
    float m_horsePower;
public:
    DieselCar() = delete;
    DieselCar(const DieselCar&) = delete;
    DieselCar(DieselCar&&) = delete;
    DieselCar& operator=(const DieselCar&) = delete;
    DieselCar& operator=( DieselCar&&) = delete;
    ~DieselCar() = default;

    DieselCar(std::string brand, std::string model, float mileage, float horsepower);

    std::string brand() const { return m_brand; }

    std::string model() const { return m_model; }

    float mileage() const { return m_mileage; }

    float horsePower() const { return m_horsePower; }

    friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);

    
};

#endif // DIESELCAR_H


