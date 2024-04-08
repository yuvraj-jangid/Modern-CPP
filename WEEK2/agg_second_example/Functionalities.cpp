#include "Functionalities.h"

void CreateObjects(Employee **employees, Project **projects)
{
    projects[0] = new Project("Pr101", 66700.0f, 11);
    employees[0] = new Employee("emp101", "Harshit", 56000.0f, *projects[0]);
}

void CreateObjects(std::vector<Employee*> &employees, std::vector<Project *> projects)
{
    projects[0] = new Project("Pr101", 66700.0f, 11);
    employees[0] = new Employee("emp101", "Harshit", 56000.0f, *projects[0]);
}
