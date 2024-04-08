#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include "PermitType.h"

class Permit
{
private:
    unsigned long m_serial_number;
    PermitType m_permit_type;
    unsigned int m_permit_duration_left;
public:
    Permit() = default; // default constructor enable
    Permit(const Permit&) = delete; //disabled copy constructor
    Permit(Permit&&) = delete; //disabled move constructor
    Permit& operator = (const Permit&) = delete; //deleted copy assignment operator
    Permit& operator = (Permit&&) = delete; //c++ brand new, deleted move assignment operator
   ~Permit() = default; //destructor enabled

   Permit(unsigned int serial_number, PermitType permit_type, unsigned int permit_duration_left);

   unsigned long serialNumber() const { return m_serial_number; }

   PermitType permitType() const { return m_permit_type; }

   unsigned int permitDurationLeft() const { return m_permit_duration_left; }
   void setPermitDurationLeft(unsigned int permit_duration_left) { m_permit_duration_left = permit_duration_left; }

   friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);


    

};

#endif // PERMIT_H
