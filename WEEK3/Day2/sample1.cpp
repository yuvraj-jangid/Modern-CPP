// if no. of child classes are fixed and we don't want to use inheritance then there comes variant
//  varinat is a cpp17 feature

// TaxPayers : Employees, BuisnessOwners

#include <iostream>
#include <variant> // cpp17 feature
#include <array>

class BuisnessOwner
{
private:
    /* data */
    std::string _name;
    std::string _companyGSTnumber;
    float _revenue;
    float _expenses;

public:
    float CalculateTaxAmount() { return 0.3f * (_revenue - _expenses); }
    BuisnessOwner(std::string name, std::string GST, float revenue, float expenses)
        : _name{name}, _companyGSTnumber{GST}, _revenue{revenue}, _expenses{expenses} {}
    ~BuisnessOwner() = default;

    std::string name() const { return _name; }

    float revenue() const { return _revenue; }
};

class Employee
{
private:
    /* data */
    std::string _name;
    float _salary;

public:
    Employee(std::string name, float sal) : _name{name}, _salary{sal} {}
    ~Employee() = default;

    std::string name() const { return _name; }
};

/*
    I want to use std::array as a container of variants where each variant is either of type Employee pointer or BuisnessOwner pointer
*/

using VType = std::variant<Employee *, BuisnessOwner *>;  // dono mein se koi ek hi slot active ho sakta hai dono nahi ho sakte like union in c
using Container = std::array<VType, 2>;

void CommonAction(Container &arr)
{
    for (VType v : arr)
    {
        std::visit(
            [](auto &&val) // auto&& is template parameter for lambda 
            {
               std::cout << val->name() << "\n"; 
            },
            v);
    }
}

//scenario 2 code 
/*
    for each VType (variant) called "v",
        a) open variant and if v holds an alternative of type BuisnessOwner*
        b) if yes, get data from slot 1 of the variant
                (because slot 1 is for BuisnessOwner*)
            Now, save this to a variable and access revenue
*/
void UncommonFunction(Container& arr){
    for(VType v : arr) {
        if(std::holds_alternative<BuisnessOwner*>(v)){
            BuisnessOwner* owner = std::get<1>(v); // 1 isiliye kyunki wo slot(index) 1 pe hai variant ke array ke nahi 
            std::cout << owner->revenue();
        }
    }
}
int main()
{
    Employee *emp = new Employee("Harshit", 67000.0f);
    BuisnessOwner *buisness = new BuisnessOwner("XYZ", "1910ahh", 100, 50);

    Container arr{emp, buisness};
}

/*
Employee  BuisnessOwner                                   Employee  BuisnessOwner
[ 0x100H | ////////// ]                                   [ ////// |    0x907H  ]
<-------------------------------arr---------------------------------------------->


scenario 1 :

*/
