#include "Functionalities.h"
#include <future>
int main()
{

    Container data;

    try
    {
        /* code */
        std::thread t(CreateObjects, std::ref(data));
        t.join();

        std::future<void> f1 = std::async(Common, std::ref(data));

        std::future<void> f2 = std::async(UnCommon, std::ref(data));
       f1.wait();
       f2.wait();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
