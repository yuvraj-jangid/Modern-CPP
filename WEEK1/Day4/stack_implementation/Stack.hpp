// *******************************Making STACK using linked list********************************


#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <list>
#include "StackEmptyException.hpp"

template <typename T>
class Stack
{
private:
    std::list<T> _data {};

public:
    Stack() = default; // default constructor
    Stack(const Stack&) = delete; // copy constructor 
    Stack& operator = (const Stack&) = delete; // assignment operator
    Stack(Stack&&) = default; // move constructor
    Stack& operator = (stack&&) = default; // move assignment operator
    ~Stack() = default;

    void Pop();

    /*
        Push function accepts one item "val" of type T
        return void
    */ 


    Push(T val){
        _data.push_back(val);
    }


    //give view of top element
    T Peek() {
       if( _data.empty()){
        // throw stack empty!!!!!!
       }  
        return _data.back();
    }  


    size_t Size(){ // size_t is an unsigned int or long datatype
        return _data.size();
    }



    bool IsEmpty() {
        return _data.empty();
    }
};



#endif // STACK_HPP




/*
    |     |    |    int
    <----------------0----------------->
    unsigned int
    unsigned long

*/

template <typename T>
inline void Stack<T>::Pop()
{
        if(_data.empty()){
            // throw data empty
        }

        _data.pop_back();
}
