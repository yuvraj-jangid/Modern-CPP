#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(unsigned long number, TouristVehicleType type, unsigned int seat_count, float per_hour_booking_charge, unsigned int serial_number, PermitType permit_type, unsigned int permit_duration_left)
:m_number{number}, m_type{type}, m_seat_count{seat_count}, m_per_hour_booking_charge{per_hour_booking_charge}, m_permit(std::make_shared<Permit>(serial_number, permit_type, permit_duration_left))
{}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    std::string val {""};
    if(rhs.m_type == TouristVehicleType::BIKE){
        val = "BIKE";
    }
    else if(rhs.m_type == TouristVehicleType::BUS){
        val = "BUS";
    }
    else {
        val = "CAB";
    }
    os << "m_number: " << rhs.m_number
       << " m_type: " << val
       << " m_seat_count: " << rhs.m_seat_count
       << " m_per_hour_booking_charge: " << rhs.m_per_hour_booking_charge
       << " m_permit: " << *rhs.m_permit; // *rhs show krega permit ki value aur agar sirf rhs hota toh permit ka address print krta 
    return os;
}


/*
int x = 10;
int *ptr = &x;

ptr --> show x ka address;
*ptr --> show x ki value;
&ptr --> show ptr ka address

*/
