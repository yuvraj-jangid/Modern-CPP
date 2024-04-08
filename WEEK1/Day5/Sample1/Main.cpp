#include "Functionalities.h"
#include "Car.h"

int main(){      
    Container data ;
    CreateObjects(data);
    try{
        int ans = TotalHorsepower(data);
        std::cout << "Total Horsepower is: " << ans <<"\n";
        float result = AverageEngineTorque(data);
        std::cout << "Average Value is: " << result << "\n";
        std :: string model = FindCarModelById(data, "c101");
        std::cout << "Model for given ID found" << model << "\n";
        bool flag = IsContainerAllCarAbove700000(data);
        if(flag){
            std::cout<< "All vehicles have price above 7 lacs\n";
        }
        else{
            std::cout << "Some vehicles have price below 7 lacs\n";
		}

        Engine* e = EnginePointerToMinPriceCar(data);
        std::cout << "Engine found: " << *e << "\n";
        DeleteObjects(data);
    }
    catch(const EmptyContainerException& ex){
        std::cerr << ex.what() << "\n";
    }
    catch(const IdNotFoundException& ex){
        std::cerr << ex.what() << "\n";
    }

}
