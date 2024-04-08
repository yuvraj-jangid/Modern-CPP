#include "Car.h"

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "m_name: " << rhs.m_name
       << " _acceleration: " << rhs._acceleration
       << " _top_speed: " << rhs._top_speed
       << " _ex_showroom_price: " << rhs._ex_showroom_price;
    return os;
}

Car::Car(std::string name, int acceleration, int top_speed, float price)
    //at the place of this-> we can use like _name{name} this is how we write in modern cpp
    : m_name{name}, _acceleration{acceleration}, _top_speed{top_speed}, _ex_showroom_price{price} {} 



