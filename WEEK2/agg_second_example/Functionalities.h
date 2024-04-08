#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Employee.h"
#include "Project.h"

#include <iostream>

void CreateObjects(Employee **employees, Project **projects);

void CreateObjects(std::vector<Employee*> &employees, std::vector<Project*>);

#endif // FUNCTIONALITIES_H
