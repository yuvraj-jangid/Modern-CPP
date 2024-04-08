#include <iostream>

enum class 


class EngineDummy
{
private:
    
    
public:
    EngineDummy() {}
    ~EngineDummy() {}

    friend std::ostream &operator<<(std::ostream &os, const EngineDummy &rhs) { return os; }



    

};
