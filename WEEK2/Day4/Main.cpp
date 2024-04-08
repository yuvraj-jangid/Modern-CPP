#include "Functionalities.h"

void line(){
    std::cout << "\n\n----------------------------------------------------------\n\n";
}

int main() {
    Container data {1,2,3,4,5};
    try
    {
        Adaptor(lfn1, data);

        line();

        Adaptor(lfn2, data);
        
        line();
        
        Adaptor(lfn3, data);

        line();
    }
    catch(std::runtime_error& ex)
    {
        std::cout << ex.what() << '\n';
    }
    
}
