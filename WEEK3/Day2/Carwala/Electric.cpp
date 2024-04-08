#include "Electric.h"
std::ostream &operator<<(std::ostream &os, const Electric &rhs) {
    os << "m_brand: " << rhs.m_brand
       << " m_model: " << rhs.m_model
       << " m_range: " << rhs.m_range
       << " m_maxpower: " << rhs.m_maxpower;
    return os;
}

Electric::Electric(std::string brand, std::string model, float range, float maxpower)
: m_brand{brand}, m_model{model}, m_range{range}, m_maxpower{maxpower}
{
}
