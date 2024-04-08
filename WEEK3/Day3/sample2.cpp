#include <future>
#include <iostream>

void Factorial(std::future<int> &ft){
    int* ptr = (int*) malloc(4); // line can be executed before int
    // wait for the event 
    int n = ft.get(); // this thread will now get block till the input comes


    int result = 1;
    for (int i = 0; i <= n; i++)
    {
        result *= i;
    }

    *ptr = result;
    std::cout << "Final answer is: " << *ptr << "\n";
    
}

int main() {
    // make a promise to compiler, I will give you an integer IN FUTURE
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<void> result = std::async( &Factorial, std::ref(ft));
    int value = 0;
    std::cin >> value;
    //promise fulfil
    pr.set_value(value); // notify

    // what if main wants to do something after Factorial?
    result.wait(); // it is like join // matlab ab ye async wala kaam khatam hogaya h 
    std::cout << "goodbye\n";

}

// promise is used to set the value in producer thread
// future is used to getting the value in consumer thread
