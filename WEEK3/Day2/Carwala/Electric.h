#ifndef ELECTRIC_H
#define ELECTRIC_H

#include <iostream>

class Electric
{
private:
    std::string m_brand;
    std::string m_model;
    float m_range;
    float m_maxpower;
public:
    Electric() = default; // default constructor enable
    Electric(const Electric&) = delete; //disabled copy constructor
    Electric(Electric&&) = delete; //disabled move constructor
    Electric& operator=(const Electric&) = delete; //deleted copy assignment operator
    Electric& operator=(Electric&&) = delete; //c++ brand new, deleted move assignment operator
    ~Electric() = default; //destructor enabled

    Electric(std::string brand, std::string model, float range, float maxpower);

    std::string brand() const { return m_brand; }
    void setBrand(const std::string &brand) { m_brand = brand; }

    std::string model() const { return m_model; }
    void setModel(const std::string &model) { m_model = model; }

    float range() const { return m_range; }
    void setRange(float range) { m_range = range; }

    float maxpower() const { return m_maxpower; }
    void setMaxpower(float maxpower) { m_maxpower = maxpower; }

    friend std::ostream &operator<<(std::ostream &os, const Electric &rhs);


    
};

#endif // ELECTRIC_H
