
#include <iostream>
#include <array>
#include <thread>
#include <mutex>

/*
                                                    -------------------->Cube Ends
                                                    |                        |   
                                                    |                        |
    program starts                                  |                        |
    ----------------->Square starts           Cube Starts                    Program Ends
                            |                       |
                            |                       |
                            |                       |
                            ------------------>Square Ends

****************************************************************************************************************************
CONCURRENCY, PARALELLISM ETC

                       /--------------Square start------------------
                      /
                     /
                    /
--------starts------                                                ---------------------STOPS!
                    \
                     \
                      \
                       \---------------Cube start-------------------

*/

std::mutex mt;

void Square(std::array<int, 5>& data){
    for(int number : data){
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // only 1 executing entity should be doing this
        mt.lock(); // use of mutex 
        std::cout << "Square of: " << number << " is: " << number*number << "\n";
        mt.unlock();
    }
}


void Cube(std::array<int, 5>& data){
    for(int number : data){
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // only 1 executing entity should be doing this
        mt.lock();
        std::cout << "Cube of: " << number << " is: " << number*number << "\n";
        mt.unlock();
    }
}


int main(){
    // main thread starts create an array objects in local stack memory

    std::array<int, 5> arr{1,2,3,4,5};

    // Square(arr);
    // Cube(arr);

    // we launch a new thread
    /*
        A thread is a mini program. As the developer, t1 object is a "handle" for me to interact with the thread in some way.
        This t1 is attached to Square mini program we have also passed "data" by reference which is required by the Square function
    */

    std::thread t1(&Square, std::ref(arr)); // made square a thread

    /*
        This t2 is attached to Cube mini program
        We have also passed "data" by reference which is required by the cube function
    */
    std::thread t2(&Cube, std::ref(arr)); // made cube a thread

    // SIGNAL AS A RESULT/SUMMARY/SATISFACTION

    // signal came when main is alive

    // join : wait for a thread
    /*
        use - lpthread for g++ to run thread 

        join nahi lagaya toh runtime exception aayegaa
    */

   t1.join(); // main will not procced to next line until t1 finished
   //not goes to next instructions until the signal is arrive
   /*
   t1.join()
    a - t1 crashes --> exception --> still give signal to main
    b - t1 does finish even before t2 starts
    c - t2 already finish even before t1 is started
    and many more at the end it still give signal
   */
   t2.join(); // main will not procced to next line until t2 finished

//    JOIN NAHI LAGAYA TOH RUNTIME EXCEPTION AAYEGA
    mt.lock();
    std::cout << "\nBYE BYE! Main ended\n";
    mt.unlock();
}


/*
THREAD : is a set of instructions which is a independent mini program 
    is a mini program
    you technical losse control to it because OS handles it (we cannot decide which we have to run fist)
    whenever you are running thread you are talking about memory level execution 
*/
