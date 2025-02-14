#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>

class Project
{
private:
std::string _project_id;
float _project_budget;
unsigned int _team_size;

public:
    Project() = default;
    Project(const Project&) = delete;
    Project& operator=(const Project&) = delete;
    Project&& operator=(Project&&) = delete;
    Project(Project&&) = delete;    
    ~Project() = default;

    Project(std::string project_id, float project_budget, unsigned int team_size);

    std::string projectId() const { return _project_id; }

    float projectBudget() const { return _project_budget; }
    void setProjectBudget(float project_budget) { _project_budget = project_budget; }

    unsigned int teamSize() const { return _team_size; }
    void setTeamSize(unsigned int team_size) { _team_size = team_size; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);

    
};

#endif // PROJECT_H
