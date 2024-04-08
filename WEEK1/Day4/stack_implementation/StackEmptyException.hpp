#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include <stdexcept>
#include <cstring>

class StackEmptyException : public std::exception
{
private:
    char* _msg;
public:

    StackEmptyException() = delete;

    explicit StackEmptyException(const char* msg) {
        // step 1 : allocate memory space for _msg data member.
        // this should same as length of msg + 1
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg); //destination. source
    }
    ~StackEmptyException() {
        delete _msg;
    }


    StackEmptyException (const StackEmptyException&) = delete;
    StackEmptyException& operator=(const StackEmptyException&) = delete;

    StackEmptyException (StackEmptyException&&) = default; // move constructor
    StackEmptyException&& operator=(StackEmptyException&&) = delete;

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return _msg;
    }
};

#endif // STACKEMPTYEXCEPTION_HPP






/*
    Pop 
    throw StackEmptyException("Data is empty")
    [this calls constructor of custom exception class]
    |
    |
*/
