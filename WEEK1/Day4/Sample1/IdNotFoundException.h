#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <cstring>

class IdNotFoundException : public std::exception
{
private:
     char* _msg;
public:
    IdNotFoundException() = delete;
    IdNotFoundException(const IdNotFoundException&) = delete;
    IdNotFoundException(IdNotFoundException&&) = default;
    IdNotFoundException& operator = (const IdNotFoundException&) = delete;
    IdNotFoundException&& operator = (IdNotFoundException&&) = delete;

    /*
        parametrized constructor
    */
    IdNotFoundException(const char* msg) {
        
        _msg = new char[strlen(msg) + 1];  // + 1 hoana chahiye kyun ki null pointer ke liye 1 byte hona chahiye
        strcpy(_msg,msg);
    }
    ~IdNotFoundException() {
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // IDNOTFOUNDEXCEPTION_H
