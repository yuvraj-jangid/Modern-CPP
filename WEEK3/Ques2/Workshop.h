#ifndef WORKSHOP_H
#define WORKSHOP_H

#include<iostream>
#include<variant>
#include"WorkshopType.h"

class Workshop{
private:
    std::variant<std::string, int> _centre_id;
    int _service_point_count;
    WorkshopType __type;
    int _token_number;
    static int auto_token;
    int attendant_count;
    float _evaluation_value;
    int _current_class;

public:
    Workshop() = delete;                     // deleted default constructor
    Workshop(const Workshop&) = default;       // deleted copy constructor
    Workshop(Workshop &&) = delete;           // delete move constructor
    Workshop operator=(Workshop &) = delete;  // delete copy assignment operator
    Workshop operator=(Workshop &&) = delete; // delete move assignment operator
    ~Workshop() = default;                   //enabled destructor


    Workshop(std::variant<std::string, int> id, int service, WorkshopType type, int auto_token, int attendant, float eval, int current);

    std::variant<std::string, int> centreId() const { return _centre_id; }

    int servicePointCount() const { return _service_point_count; }

    WorkshopType type() const { return __type; }


    int attendantCount() const { return attendant_count; }

    float evaluationValue() const { return _evaluation_value; }

    int currentClass() const { return _current_class; }

    static int autoToken() { return Workshop::auto_token; }

    int tokenNumber() const { return _token_number; }

    friend std::ostream &operator<<(std::ostream &os, const Workshop &rhs);

};

std::string DisplayEnum(WorkshopType type);

#endif // WORKSHOP_H
