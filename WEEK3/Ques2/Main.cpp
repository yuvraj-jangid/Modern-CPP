#include <iostream>
#include "WorkshopType.h"
#include "Workshop.h"
#include "Location.h"
#include "Functionalities.h"

#include <memory>
#include <algorithm>
#include <numeric>
#include <thread>

using LocationPointer = std::shared_ptr<Location>;
using LocationContainer = std::vector<LocationPointer>;

using WorkshopPointer = std::shared_ptr<Workshop>;
using WorkshopContainer = std::vector<WorkshopPointer>;

int main()
{
    WorkshopContainer wdata;
    LocationContainer data;

    try
    {
        std::thread t1(&CreateObjects, std::ref(data), std::ref(wdata));

        t1.join();
    }
    catch (const std::exception e)
    {
        std::cerr << e.what();
    }

    try
    {
        std::thread t2(&First2AttendantCount, std::ref(data));

        std::thread t3(&CheckLocationHasWorkshop, std::ref(data), 4000.0f);

        std::thread t4(&FindNInstances, std::ref(data), 3);

        std::thread t5(&AverageEvaluationAmount, std::ref(data));

        std::thread t6(&PrintDetails, std::ref(data));

        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
    }
    catch (const std::exception e)
    {
        std::cerr << e.what();
    }
}