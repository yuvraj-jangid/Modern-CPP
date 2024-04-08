/*
    Objective:
    Design a consumer for:
        - making allocations on the heap for 10 integers
        - Save square of first 10 integers on the heap storage created
        - calculating sum of first N natural numbers, where N is accepted 
        asynchronously in the function and return the value
    Producer thread for :
        - Launch a consumer accepting N and passing to the consumer
*/
#include <iostream>
#include <future>

//***IMP** : ek future class ke liye ek hi baar get kr sakte hai 

int Consumer(std::future<int>& ft){
    int* ptr = (int*)malloc(40);
    auto f1 = [](int number) {return number * number; };

    for(int i=1; i<=10; i++){
        ptr[i-1] = f1(i);
    }

    for(int i=1; i<=10; i++){
        std::cout << ptr[i-1] << "\n";
    }

    int n = ft.get();
    return (n*(n+1)/2);
}

int main() {
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();

    std::future<int> result = std::async( &Consumer, std::ref(ft));
    int value {0};
    std::cin >> value;
    pr.set_value(value);

    std::cout << "The answer is: " << result.get() << '\n';
}
