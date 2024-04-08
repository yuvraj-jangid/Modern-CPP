//objective :  make shared ke bina pointer banna chahiye 

// we have to make only 1 object not zero not more than 1 so we will make singleton class 

#include <iostream>
#include <mutex>
#include <thread>
#include <array>

/*
    one object of this class will be responsible for one connection mechanism to the bank
*/

class BankingOperation;

using BankingPtr = std::shared_ptr<BankingOperation>;

class BankingOperation
{
private:
    int m_amount{0};
    std::mutex mt;
    static BankingOperation m_solo_hero_obj;
    
    BankingOperation(int amount) : m_amount(amount) {}  // parametrized constructor

public:
    ~BankingOperation() = default; //destructor enabled
    BankingOperation(const BankingOperation&) = delete; //disabled copy constructor
    BankingOperation(BankingOperation&&) = delete; //disabled move constructor
    BankingOperation& operator=(const BankingOperation&) = delete; //deleted copy assignment operator
    BankingOperation& operator=(BankingOperation&&) = delete; //c++ brand new, deleted move assignment operator


    void withdraw(){
    for(int i = 0;i<100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lk(mt);
        m_amount -= 10;
    }
}

void deposit(){
    for(int i = 0;i<100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::lock_guard<std::mutex> lk(mt);
        m_amount += 10;
    }
}

static BankingPtr getFirstInstance(int amount){
    // if pointer is not null (valid), object already exists 
    if(m_solo_hero_obj){
        //return address of existing object
        return m_solo_hero_obj;
    } else {
        //no object is pre-existing. Need to make a new one
        m_solo_hero_obj.reset(new BankingOperation(amount)); // reset kiya h yaha  
        return m_solo_hero_obj;
    }
}

int amount() const { return m_amount; }

};

BankingPtr BankingOperation::m_solo_hero_obj{nullptr};

int main(int argc, char const *argv[])
{
    BankingPtr obj = BankingOperation::getFirstInstance(1000); // value initialization using {}
    //int arr[2] = {10, 20};
    std::array<std::thread, 2> arr = {
        std::thread(&BankingOperation::withdraw, obj),
        std::thread(&BankingOperation::deposit, obj)
    };

    for(std::thread& t : arr){
        // good practice

        if(t.joinable()){ // true aaya toh still wait! 
            t.join();
        }
    }
    
    std::cout << "Final amount is: " << obj->amount() <<"\n";

    return 0;
}

