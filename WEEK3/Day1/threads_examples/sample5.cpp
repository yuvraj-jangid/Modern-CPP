#include <iostream>
#include <mutex>
#include <thread>
#include <array>

class BankingOperation
{
private:
    int m_amount{0};
    std::mutex mt;

public:
    BankingOperation(int amount) : m_amount(amount) {} // parametrized 
    BankingOperation(const BankingOperation&) = delete; //disabled copy constructor
    BankingOperation(BankingOperation&&) = delete; //disabled move constructor
    BankingOperation& operator=(const BankingOperation&) = delete; //deleted copy assignment operator
    BankingOperation& operator=(BankingOperation&&) = delete; //c++ brand new, deleted move assignment operator
    ~BankingOperation() = default; //destructor enabled

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
        mt.lock();
        m_amount += 10;
        mt.unlock();
    }
}
};

int main(int argc, char const *argv[])
{
    BankingOperation b1{1000}; // value initialization using {}
    //int arr[2] = {10, 20};
    std::array<std::thread, 2> arr = {
        std::thread(&BankingOperation::withdraw, b1),
        std::thread(&BankingOperation::deposit, b1)
    };

    for(std::thread& t : arr){
        // good practice

        if(t.joinable()){ // true aaya toh still wait! 
            t.join();
        }
    }
    
    return 0;
}

// we have to make only 1 object not zero not more than 1 so we will make singleton class 
