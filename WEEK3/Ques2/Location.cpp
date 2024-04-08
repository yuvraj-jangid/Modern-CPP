#include "Location.h"

std::ostream &operator<<(std::ostream &os, const Location &rhs) {
    os << "_name: " << rhs._name
       << " _workshop: " << rhs._workshop;
    return os;
}

Location::Location(std::string name, WorkshopPointer workshop)
            : _name(name), _workshop(workshop)
{
}
