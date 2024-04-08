#include <iostream>

// --------------DYNAMIC METHOD DISPATCH----------------


class Parent
{
private:
    /* data */
public:
    Parent(/* args */) {}
    ~Parent() {}

    virtual void magic() = 0;
    virtual ~Parent() {}
};

class Child : public Parent
{
private:
    /* data */
public:
    Child(/* args */) {}
    virtual ~Child() {}

    void ChildDisplay() {std::cout << "DONE!\n";}
    void magic() override {std::cout << "magic from child\n";}
};


int main(){
    float f1 = 10.21f;
    // int n1 = (float) f1;
    // int n1 = (float) "Harshit"; // C STYLE CAST // it will give error
    int n1 = static_cast<int>(f1); // this is <target> // this is called as static cast // C++ STYLE CAST

    // std::cout << n1 << "\n"; //lossy conversion

    // TYPE 2 : CAST WHEN PARENT-CHILD RUNTIME POLYMORPHISM IS IN PICTURE
        //2A CONVERTING REFERENCE : if conversion fails, we will get exception of type badcast
        Parent* ptr = new Child(); //upcasting
        try{
            Child& ch = dynamic_cast<Child&>(*ptr);
        }catch(std::bad_cast& ex){
            // do something failure
        }
        // converting references will lead to an exception



        //2B CONVERTING POINTER : if conversion fails, we get nullptr
        Parent* ptr = new Child(); //upcasting
        ptr->magic(); //ptr type is Parent. Function is virtual
        Child* temp = dynamic_cast<Child*>(ptr);
}


// **************if you want to use dynamic cast atleast one function in base class should be virtual******************
// your base class destructor must be virtual if you are using upcasting


// PARENT MEIN VIRTUAL DIKHNA CHAHIYE DYNAMIC CAST KE LIYE 
