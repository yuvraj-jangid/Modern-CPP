#include "Functionalities.h"

void Adaptor(FnType fn, Container &data)
{
    if(data.empty()){
        throw std::runtime_error("Data is not available for adaptor to do anything");
    }
    fn(data);
}

FnType lfn1 = [](Container& data) { std::cout << data.front();};
FnType lfn2 = [](Container& data) { std::cout << data.back();};
FnType lfn3 = [](Container& data) { std::cout << data.size();};

