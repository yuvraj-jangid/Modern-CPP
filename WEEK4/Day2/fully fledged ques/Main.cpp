#include "Functionalities.h"
#include "Car.h"
#include <thread>
#include <future>

int main(){      
    Container data ;
    CreateObjects(data);
    std::thread t1 (CreateObjects, std::ref(data)); // using thread 
    t1.join();
    try{
        //using async and future
        std::future<int> ans = std::async(&TotalHorsepower, std::ref(data));
        std::cout << "Total Horsepower is: " << ans.get() <<"\n"; // .get lagana padega access yaa print krne ke liye

        std::future<float> result = std::async(&AverageEngineTorque, std::ref(data));
        std::cout << "Average Value is: " << result.get() << "\n";

        std::future<std::string> model = std::async(&FindCarModelById, std::ref(data), "c101");
        std::cout << "Model for given ID found: " << model.get() << "\n";

        std::future<bool> flag = std::async(&IsContainerAllCarAbove700000, std::ref(data));
        if(flag.get()){
            std::cout<< "All vehicles have price above 7 lacs\n";
        }
        else{
            std::cout << "Some vehicles have price below 7 lacs\n";
        }

        std::future<Engine*> e = std::async(&EnginePointerToMinPriceCar, std::ref(data));
        std::cout << "Engine found: " << *(e.get()) << "\n";
    }catch(const std::future_error &ex){
        //std::cerr << ex.what() << "\n";
        if(ex.code() == std::future_errc::no_state){
        	std::cout << "Missing input/result value\n";
        }
        
        if(ex.code() == std::future_errc::future_already_retrieved){
        	std::cout << "You already fetched the value. don't try again!\n";
        }
        
    }

}
