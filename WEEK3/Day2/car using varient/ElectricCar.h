#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include <iostream>

class ElectricCar
{
private:
    std::string m_brand;
    std::string m_model;
    float m_range;
    float m_maxpower;
public:
    ElectricCar() = delete;
    ElectricCar(const ElectricCar&) = delete;
    ElectricCar(ElectricCar&&) = delete;
    ElectricCar& operator = (const ElectricCar&) = delete;
    ElectricCar& operator = (ElectricCar&&) = delete;
    ~ElectricCar() = default;

    ElectricCar(std::string brand, std::string model, float range, float maxpower);

    std::string brand() const { return m_brand; }

    std::string model() const { return m_model; }

    float range() const { return m_range; }

    float maxpower() const { return m_maxpower; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);
};

#endif // ELECTRICCAR_H
