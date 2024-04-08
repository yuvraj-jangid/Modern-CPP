#ifndef DIESELCAR_H
#define DIESELCAR_H

#include <iostream>

class DieselCar
{
private:
    std::string m_brand;
    std::string m_model;
    float m_mileage;
    float m_horsepower;
public:
    DieselCar() = default;
    DieselCar(const DieselCar& ) = delete;
    DieselCar(DieselCar&&) = delete;
    DieselCar& operator=(const DieselCar&) = delete;
    DieselCar& operator=(DieselCar&&) = delete;
    ~DieselCar() = default;

    DieselCar(std::string brand, std::string model, float mileage, float horsepower);

    std::string brand() const { return m_brand; }
    void setBrand(const std::string &brand) { m_brand = brand; }

    std::string model() const { return m_model; }
    void setModel(const std::string &model) { m_model = model; }

    float mileage() const { return m_mileage; }
    void setMileage(float mileage) { m_mileage = mileage; }

    float horsepower() const { return m_horsepower; }
    void setHorsepower(float horsepower) { m_horsepower = horsepower; }

    friend std::ostream &operator<<(std::ostream &os, const DieselCar &rhs);


    
};

#endif // DIESELCAR_H
