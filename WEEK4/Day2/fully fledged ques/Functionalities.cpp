#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace("c101",  std::make_shared<Car>("c101", "Honda City", std::make_shared<Engine>(103, 67.8f), CarType::SEDAN));
    data.emplace("c102",  std::make_shared<Car>("c102", "XUV 700", std::make_shared<Engine>(150, 97.8f), CarType::SUV));
    data.emplace("c101",  std::make_shared<Car>("c103", "VW Golf", std::make_shared<Engine>(120, 90.8f), CarType::HATCHBACK));
}


int TotalHorsepower(const Container &data)
{
    if (data.empty()){
        throw IdNotFoundException(std::future_errc::broken_promise,"Id not found");
    }

    float total = 0.0f;
    std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float answer_upto_current_point, const std::pair<std::string, CarPointer>& row) {
            return answer_upto_current_point + row.second->engine()->horsepower();
        }
    );

}

bool IsContainerAllCarAbove700000(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    return std::all_of(
        data.begin(),
        data.end(),
        [](std::pair<const std::string, CarPointer>& row) {
            return row.second->price() > 700000.0f;
        }
    );
}

Engine *EnginePointerToMinPriceCar(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    auto itr = std::min_element{
        data.begin(),
        data.end(),
        [](std::pair<const std::string, CarPointer>& row1, std::pair<std::string, CarPointer>& row2) {
            return row1.second->price() < row2.second->price();
        }
    };

    return (*itr).second->engine().get();

}

float AverageEngineTorque(const Container &data)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    std::size_t count{0};
    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float answer_upto_current_point, const std::pair<std::string, CarPointer>& row) {
            if(row.second->engine()){
                count++;
                return answer_upto_current_point + row.second->engine()->torque();
            }

            return answer_upto_current_point;
        }
    );

    return ans / static_cast<float> (count);

}

std::string FindCarModelById(const Container &data, const std::string carId)
{
    if (data.empty()){
        throw EmptyContainerException(std::future_errc::broken_promise,"Data is empty");
    }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](std::pair<std::string, CarPointer>& row) {
            return row.first == carId;
        }
    );

    if(itr == data.end()){
        throw std::runtime_error("ID not found\n");
    }
    else {
        return (*itr).second->model();
    }
}

