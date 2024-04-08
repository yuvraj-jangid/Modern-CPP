#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include "TouristVehicleType.h"
#include "Permit.h"
#include <iostream>
#include <memory>

using PermitPtr = std::shared_ptr<Permit>;


class TouristVehicle
{
private:
    unsigned long m_number;
    TouristVehicleType m_type;
    unsigned int m_seat_count;
    float m_per_hour_booking_charge;
    PermitPtr m_permit;

public:
    TouristVehicle() = default; // default constructor enable
    TouristVehicle(const TouristVehicle&) = delete; //disabled copy constructor
    TouristVehicle(TouristVehicle&&) = delete; //disabled move constructor
    TouristVehicle& operator = (const TouristVehicle&) = delete; //deleted copy assignment operator
    TouristVehicle& operator = (TouristVehicle&&) = delete; //c++ brand new, deleted move assignment operator
   ~TouristVehicle() = default; //destructor enabled

   TouristVehicle(unsigned long number, TouristVehicleType type, unsigned int seat_count, float per_hour_booking_charge, unsigned int serial_number, PermitType permit_type, unsigned int permit_duration_left);

   unsigned long number() const { return m_number; }

   TouristVehicleType type() const { return m_type; }

   unsigned int seatCount() const { return m_seat_count; }
   void setSeatCount(unsigned int seat_count) { m_seat_count = seat_count; }

   float perHourBookingCharge() const { return m_per_hour_booking_charge; }
   void setPerHourBookingCharge(float per_hour_booking_charge) { m_per_hour_booking_charge = per_hour_booking_charge; }

   PermitPtr permit() const { return m_permit; }

   friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
   
};

#endif // TOURISTVEHICLE_H
