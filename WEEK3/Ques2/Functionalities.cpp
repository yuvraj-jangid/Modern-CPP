#include<iostream>
#include"WorkshopType.h"
#include"Workshop.h"
#include"Location.h"
#include"Functionalities.h"

#include<memory>
#include<algorithm>
#include<numeric>


using LocationPointer = std::shared_ptr<Location>;
using LocationContainer = std::vector<LocationPointer>;

using WorkshopPointer = std::shared_ptr<Workshop>;
using WorkshopContainer = std::vector<WorkshopPointer>;

void CreateObjects(LocationContainer& data, WorkshopContainer& wdata){
    WorkshopPointer w1 = std::make_shared<Workshop>("101", 1011, WorkshopType::BOTH, 1, 3, 1000.0f, 10);
    WorkshopPointer w2 = std::make_shared<Workshop>("102", 2011, WorkshopType::REPAIRS, 2, 5, 2000.0f, 20);
    WorkshopPointer w3 = std::make_shared<Workshop>("103", 3011, WorkshopType::SERVICE, 3,2, 3000.0f, 12);
    WorkshopPointer w4 = std::make_shared<Workshop>("104", 4011, WorkshopType::REPAIRS, 4, 8, 4000.0f, 5);

    wdata.push_back(w1);
    wdata.push_back(w2);
    wdata.push_back(w3);
    wdata.push_back(w4);

    LocationPointer l1 = std::make_shared<Location>("Gurmeeet", std::ref(w1));
    LocationPointer l2 = std::make_shared<Location>("Abhay", std::ref(w2));
    LocationPointer l3 = std::make_shared<Location>("Ankit", std::ref(w3));
    LocationPointer l4 = std::make_shared<Location>("Riya", std::ref(w4));

    data.push_back(l1);
    data.push_back(l2);
    data.push_back(l3);
    data.push_back(l4);

}

//here, first sorting is done . then last 2 data are highest
void First2AttendantCount(LocationContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("DATA EMPTY!!");
    }

    std::sort(data.begin(), data.end(),[](LocationPointer& l1, LocationPointer& l2){
        return l1.get()->workshop()->attendantCount() > l2.get()->workshop()->attendantCount();
    });

    int size = data.size();

    std::cout << "Instance with highest attendant count: " << (*data[size-1].get()->workshop()) << "\n";
    std::cout << "Instance with second highest attendant count: " << (*data[size-2].get()->workshop()) << "\n";
}


// iterating through data and checking if value is greater than threhold or not
void CheckLocationHasWorkshop(LocationContainer &data, int threshold)
{
    if(data.empty()){
        throw std::runtime_error("DATA EMPTY!!");
    }

    bool flag = false;
    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](LocationPointer& l){
            flag = true;
            return l->workshop()->attendantCount() > threshold;
        }
    );

    if(flag == true){
        std::cout << "true";
    }else{
        std::cout << "false";
    }
}

//first sorting the data, checking the condition
void FindNInstances(LocationContainer &data, int N)
{
    if(data.empty()){
        throw std::runtime_error("DATA EMPTY!!");
    }

    if(N < 0 || N > data.size()){
        throw std::runtime_error("Invalid N");
    }

    std::sort(data.begin(), data.end(),[](LocationPointer& l1, LocationPointer& l2){
        return l1.get()->workshop()->currentClass() > l2.get()->workshop()->currentClass();
    });

    

    int count = 0;

    int size = data.size();

    while(count < N){
        std::cout << *data[count].get()->workshop() << "\n";
        count++;
    }

}

//checking condition and calculation average
void AverageEvaluationAmount(LocationContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("DATA EMPTY!!");
    }

    float total = 0.0f;

    int count = 0;

    bool flag = false;

    for(auto& val : data){
        if(val->workshop()->type() == WorkshopType::REPAIRS){
            total += val->workshop()->evaluationValue();
            count++;
            flag = true;
        }
    }

    std::cout << "Average Evaluation Amount is: " << total/count << "\n";

    if(flag == false){
        throw std::runtime_error("No instance with workshop type REPAIRS exist");
    }
  

}

//printing details by taking token number from user

void PrintDetails(LocationContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("DATA EMPTY!!");
    }
    int token_num;
    std::cout << "Enter token number: ";
    std::cin >> token_num;

    bool flag = false;

    for(auto& val : data){
        if(val->workshop()->autoToken() == token_num){
            std::cout << "name: " << val->name() << "\n";
            std::cout << "attendant count: " << val->workshop()->attendantCount() << "\n";
            flag = true;
        }
    }

    if(flag == false){
        std::cout << "first instance name: " << data.begin()->get()->name() <<"\n";
        std::cout << "first instance attendant count: " << data.begin()->get()->workshop()->attendantCount() <<"\n";
    }

    
}
