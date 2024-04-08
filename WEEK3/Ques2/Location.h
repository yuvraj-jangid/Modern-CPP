#ifndef LOCATION_H
#define LOCATION_H

#include<iostream>
#include"Workshop.h"
#include<memory>
#include<vector>

using WorkshopPointer = std::shared_ptr<Workshop>;
using WorkshopContainer = std::vector<WorkshopPointer>;



class Location{
private:
    std::string _name;
    WorkshopPointer _workshop;

public: 
    Location() = delete;                     // deleted default constructor
    Location(const Location&) = delete;       // deleted copy constructor
    Location(Location &&) = delete;           // delete move constructor
    Location operator=(Location &) = delete;  // delete copy assignment operator
    Location operator=(Location &&) = delete; // delete move assignment operator
    ~Location() = default;                   //enabled destructor

    Location(std::string name, WorkshopPointer workshop);

    std::string name() const { return _name; }

    WorkshopPointer workshop() const { return _workshop; }

    friend std::ostream &operator<<(std::ostream &os, const Location &rhs);

   

    
};

#endif // LOCATION_H
