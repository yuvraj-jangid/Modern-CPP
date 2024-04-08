/*
    Producer consumer problem!
    
    2 workers in your program
        1 _ may produce "something"
        the other will "consume it" (process the produced item)

*/

/*
    2 threads (2 workers)
        - main thread (producer) : take input and "make value available"
        - operation (t1)[consumer] : once a signal is received from main 
            to indicate "input received", calculate the square

            a) Programmer calculates how many workers are 
            required and triggers them at a time [thread pooling!]

            b) t1 may want to do some other work even before data input is received
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

int value = 0;
std::mutex mt;
std::condition_variable cv;
bool flag = false;


void operation() {
    int* ans = (int*) malloc(4);

    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&](){return flag;}); // if false, release mutex immideately
    
    *ans = value * value;
    std::cout << "Square of " << value << "is: " << *ans;
    free (ans);
}

void TakeInput(){
    //apply lock on mutex
    //  no other thread can apply lock on the same mutex before TakeInput
    std::lock_guard<std::mutex> lg(mt);

    //take input form user into global variable
    std::cin >> value;
}


int main(){
    // step 1 : thread instantiated
    // a new thread is now available  to be scheduled. (as good as already started)
    std::thread t1(&operation);

    TakeInput();
    //toggle flag to indicate "production ready"
    flag = true;

    //send a signal
    cv.notify_one();

    //wait for operation to finish before terminating the program
    t1.join();
}
