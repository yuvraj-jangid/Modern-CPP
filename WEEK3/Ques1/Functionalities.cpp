#include "Functionalities.h"

/*
   Function for Creating the Object using smart Pointers
*/
void CreateObject(Container &data)
{
    data.push_back(std::make_shared<ChargingUnit>("ch101", 2.0f, std::vector<float>{2.0f, 3.0f, 4.0f, 5.0f, 1.0f}, 15.0f, 5000.0f));
    data.push_back(std::make_shared<ChargingUnit>("ch202", 3.0f, std::vector<float>{3.0f, 2.0f, 5.0f, 4.0f, 2.0f}, 16.0f, 6000.0f));
    data.push_back(std::make_shared<ChargingUnit>("ch303", 4.0f, std::vector<float>{2.0f, 3.0f, 4.0f, 7.0f, 1.0f}, 17.0f, 10000.0f));
    data.push_back(std::make_shared<ChargingUnit>("ch404", 5.0f, std::vector<float>{2.0f, 3.0f, 4.0f, 8.0f, 90.0f}, 107.0f, 12000.0f));
    data.push_back(std::make_shared<ChargingUnit>("ch505", 6.0f, std::vector<float>{2.0f, 3.0f, 9.0f, 5.0f, 1.0f}, 20.0f, 15000.0f));
}

std::vector<float> GstAmount(Container &data)
{
    std::vector<float> r;
    float amount = 0;
    for (auto &i : data)
    {
        amount = 0;
        std::visit([&](auto &&X)
                   {
            for(int i=0;i<5;i++){
                amount+=X[i];
            } },
                   i->last5DischargedUnits());
        if (amount > 100)
        {
            amount = (amount * 18) / 100;
        }
        else
        {
            amount = amount / 10;
        }
        r.push_back(amount);
    }
    return r;
}

std::array<float, 2> CostPerKW(Container &data)
{
    std::array<float, 2> result;
    float highest = 0.0f, second_highest = 0.0f;
    float costpervalue1 = 0.0f, costpervalue2 = 0.0f;
    for (auto &i : data)
    {
        if (highest < i->capacity())
        {
            highest = i->capacity();
            costpervalue1 = i->costPerKw();
        }
    }
    for (auto &i : data)
    {
        if (second_highest < i->capacity() && (i->capacity() < highest))
        {
            second_highest = i->capacity();
            costpervalue2 = i->costPerKw();
        }
    }
    result[0] = costpervalue1;
    result[1] = costpervalue2;

    return result;
}

bool CheckValueOfRating(Container &data, float kw)
{
    bool b = false;
    for (auto &i : data)
    {
        if (i->ratingKw() >= kw)
        {
            b = true;
            break;
        }
    }
    return b;
}

Container FindInstancerById(Container &data, std::vector<std::string> ids)
{
    Container r;
    for (auto &i : data)
    {
        for (auto &a : ids)
        {
            if (a == i->id())
            {
                r.push_back(i);
            }
        }
    }
    return r;
}

float AverageRatingKwByCostPerKw(Container &data, float cost_per_kw)
{
    float r;
    int count = 0;
    for (auto &i : data)
    {
        if (i->costPerKw() > cost_per_kw)
        {
            r = i->costPerKw();
            count++;
        }
    }
    return r / count;
}
