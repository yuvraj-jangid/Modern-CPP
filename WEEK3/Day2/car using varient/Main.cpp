#include "Functionalities.h"

int main() {

    Container data;
    FnContainer fn;
    ThreadContainer th;
    CreateObjects(data,fn);
    MakingThreadContainer(th,data,fn);
    JoinThread(th);
    

    // CreateObjects(data);

    // try
    // {
    //     // Common(data);
    //     Common(data);
    //     UnCommon(data);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    

}
