#ifndef EmptyException_HPP
#define EmptyException_HPP

#include <stdexcept>
#include <cstring>

class EmptyException : public std::exception
{
private:
    /* data */
    char* m_msg; //cannot use const here coz we are using strcpy and also if we do then data cannot be change
public:
    EmptyException(const char* msg) {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg,msg);
    }

    EmptyException() = delete;
    EmptyException(const EmptyException&) = delete;
    EmptyException(EmptyException&&) = default;
    EmptyException& operator=(const EmptyException&) = delete;
    EmptyException&& operator=(EmptyException&&) = delete;


    ~EmptyException() {
        delete []m_msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return m_msg;
    }
};

#endif // EmptyException_HPP
