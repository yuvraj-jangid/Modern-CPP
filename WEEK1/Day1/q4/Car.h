#ifndef CAR_H
#define CAR_H
#include <iostream>

class Car
{
private:
    std::string m_name {""}; //here m represents the data member so that's why we put m_ it's a good practice
    int _acceleration {0};
    int _top_speed {0};
    float _ex_showroom_price {0.0f}; //in curly braces we cna provide default values only if default constructor is written
public:
    Car() = default; // default constructor enable
    Car(const Car&) = delete; //disabled copy constructor
    Car(Car&&) = delete; //disabled move constructor                            
    Car& operator = (const Car&) = delete; //deleted copy assignment operator
    Car& operator = (Car&&) = delete; //c++ brand new, deleted move assignment operator
    virtual ~Car() = default; //destructor enabled
    //these are 6 members functions that we have to write and we can use default and delete we if we want

    Car(std::string name, int acceleration, int top_speed, float price);

    std::string name() const { return m_name; }
    void setName(const std::string &name) { m_name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowroomPrice() const { return _ex_showroom_price; }
    void setExShowroomPrice(float ex_showroom_price) { _ex_showroom_price = ex_showroom_price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    virtual float Drive()=0;
    
};

#endif // CAR_H
