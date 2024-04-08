/*
    create an array of 3 threads

        - thread 1 should calculate square of each number in the array
        and store in a result array (position 1 to 5)
        - thread 1 should calculate cube of each number in the array
        and store in a result array (position 6 to 10)
        - thread 1 should calculate factorial of each number in the array
        and store in a result array (position 11 to 15)

        Assumption : Numbers in the input array will be between 1 to 10
*/

#include <thread>
#include <iostream>
#include <array>
#include <mutex>

int main()
{
    std::array<int, 15> result;
    std::mutex mtx;

    std::array<std::thread, 3> threads = {
        std::thread([&]()
                    {
            for (int i = 1; i <= 5; ++i) {
                std::lock_guard<std::mutex> lock(mtx);
                result[i - 1] = i * i;
            } }),
        std::thread([&]()
                    {
            for (int i = 1; i <= 5; ++i) {
                std::lock_guard<std::mutex> lock(mtx);
                result[i + 4] = i * i * i;
            } }),
        std::thread([&]()
                    {
            for (int i = 1; i <= 5; ++i) {
                int fact = 1;
                for (int j = 2; j <= i; ++j) {
                    fact *= j;
                }
                std::lock_guard<std::mutex> lock(mtx);
                result[i + 9] = fact;
            } })};


    for (auto &t : threads)
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    for (int i = 0; i < 15; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}
