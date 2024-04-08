#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(std::make_shared<TouristVehicle>(2123, TouristVehicleType::BIKE, 2, 200.0f, 220220, PermitType::LEASE, 1 ));
    data.push_back(std::make_shared<TouristVehicle>(2134, TouristVehicleType::CAB, 12, 1000.0f, 224520, PermitType::LEASE, 6 ));
    data.push_back(std::make_shared<TouristVehicle>(2189, TouristVehicleType::BUS, 30, 3000.0f, 235620, PermitType::OWNED, 9 ));
    // make_shared is like new that we were using previously
}

Container PermitTypeCondition(const Container &data, int N)
{
    if(data.size() == 0){
        throw EmptyContainer("The Given Object is Empty");
    }

    if(N<=0){
        throw NegativeValue("The Given Number N is Negative or Zero");
    }

    if(N > data.size()){
        throw Oversized("The Number N is greater then the given container size");
    }


    Container bothcndtn;
    int count = 0;

    for(TouristVehiclePtr it : data){
        if(it->seatCount() >= 4 && it->permit()->permitType() == PermitType::LEASE){
            bothcndtn.push_back(it);
            count++;
        }
        if(count == N){ // N count
            break;
        }
        

    }
    if(count != N){ 
        throw Oversized("The given number N is higher than the instances");
    }
    return bothcndtn;
}

float AvgPerType(const Container &data, int N)
{
    if(data.size() == 0){
        throw EmptyContainer("The Given Object is Empty");
    }

    int sum = 0;
    int count = 0;
    TouristVehicleType tvt;
    if(N == 1){
        tvt = TouristVehicleType::BIKE;
    }
    else if(N == 2){
        tvt = TouristVehicleType::BUS;
    }
    else if(N == 3){
        tvt = TouristVehicleType::CAB;
    }
    else{
        throw WrongType("You have entered an INVALID Input");
    }

    for(TouristVehiclePtr it : data) {
        if(it->type() == tvt){
            sum += it->perHourBookingCharge();
            count++;
        }
    }
    return sum/count;
}

unsigned long MaxPerBookingCharge(const Container &data)
{
    if(data.size() == 0){
        throw EmptyContainer("The Given Object is Empty");
    }

    unsigned long serial = -1; // -1 se toh jyada hi hoga charge isiliye humne = -1 le liya hai 
    float charge = -1;

    for(TouristVehiclePtr it : data){
        if(it->perHourBookingCharge() > charge){
            charge = it->perHourBookingCharge();
            serial = it->permit()->serialNumber();
        }
    }
    return serial;
}

Container FirstNinstances(const Container &data, int N)
{
    if(data.size() == 0){
        throw EmptyContainer("The Given Object is Empty");
    }

    if(N<=0){
        throw NegativeValue("The Given Number N is Negative or Zero");
    }

    if(N > data.size()){
        throw Oversized("The Number N is greater then the given container size");
    }


    std::list<TouristVehiclePtr> bothcndtn;
    int count = 0;

    for(TouristVehiclePtr it : data){
        count++;
        bothcndtn.push_back(it);
        if(count == N){
            break;
        }
    }
    return bothcndtn;
}
