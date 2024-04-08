#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include"Workshop.h"
#include"WorkshopType.h"
#include"Location.h"

using LocationPointer = std::shared_ptr<Location>;
using LocationContainer = std::vector<LocationPointer>;

using WorkshopPointer = std::shared_ptr<Workshop>;
using WorkshopContainer = std::vector<WorkshopPointer>;



/*
    A function to create 4 instances of location class
*/

void CreateObjects(LocationContainer& data, WorkshopContainer& wdata);

/*
    A function to find and print 2 instances whose attendant count is the highest
*/

void First2AttendantCount(LocationContainer& data);

/*
    A function to find and print boolean to indicate whether atleast one location has workshop 
    instance with attendant count greater than a threshold value passed as a second argument 
*/

void CheckLocationHasWorkshop(LocationContainer& data, int threshold);

/*
    A function to find and print N instances of Workshop in a container with N lowest values for
    _current_cases
*/

void FindNInstances(LocationContainer& data, int N);

/*
    A function to print average evaluation amount where workshop type is REPAIRS
*/

void AverageEvaluationAmount(LocationContainer& data);

/*
    a function to print details by taking token value from the user
*/

void PrintDetails(LocationContainer& data);

#endif // FUNCTIONALITIES_H
