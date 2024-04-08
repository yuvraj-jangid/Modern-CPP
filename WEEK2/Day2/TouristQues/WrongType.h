#ifndef WrongType_HPP
#define WrongType_HPP

#include <stdexcept>
#include <cstring>

class WrongType : public std::exception
{
private:
    /* data */
    char* m_msg; //cannot use const here coz we are using strcpy and also if we do then data cannot be change
public:
    WrongType(const char* msg) {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg,msg);
    }

    WrongType() = delete;
    WrongType(const WrongType&) = delete;
    WrongType(WrongType&&) = default;
    WrongType& operator=(const WrongType&) = delete;
    WrongType&& operator=(WrongType&&) = delete;


    ~WrongType() {
        delete []m_msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return m_msg;
    }
};

#endif // WrongType_HPP
