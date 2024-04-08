#include "Permit.h"

Permit::Permit(unsigned int serial_number, PermitType permit_type, unsigned int permit_duration_left)
: m_serial_number{serial_number}, m_permit_type{permit_type}, m_permit_duration_left{permit_duration_left}
{}

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    std::string val {""};
    if(rhs.m_permit_type == PermitType::LEASE){
        val = "LEASE";
    } else{
        val = "OWN";
    }
    os << "m_serial_number: " << rhs.m_serial_number
       << " m_permit_type: " << val
       << " m_permit_duration_left: " << rhs.m_permit_duration_left;
    return os;
}
