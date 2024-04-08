#include <iostream>

/*
    withdraw : withdraw takes 10 units of money from amount.
    deposit : adds 10 units of money to amount

    Run withdraw and deposit Both 100 times each on an initial amount

    what will be the final amount after 200 transactions are completed?
*/

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


// for((i=0; i<50; i++)); do ./app ; done // write in terminal so that you can execute your program 50 times



