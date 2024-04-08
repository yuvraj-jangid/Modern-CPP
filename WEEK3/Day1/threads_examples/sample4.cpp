#include <iostream>
#include <thread>
#include <memory>
#include <functional>
#include <mutex>

int amount = 1000;
std::mutex mt;

void withdraw(){
    for(int i = 0;i<100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mt.lock();
        amount -= 10;
        mt.unlock();
    }
}

void deposit(){
    for(int i = 0;i<100; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mt.lock();
        amount += 10;
        mt.unlock();
    }
}

int main(){
    std::thread t1(&withdraw);
    std::thread t2(&deposit);

    t1.join();
    t2.join();

    mt.lock();
    std::cout << "Amount left: " << amount << "\n";
    mt.unlock();
}
