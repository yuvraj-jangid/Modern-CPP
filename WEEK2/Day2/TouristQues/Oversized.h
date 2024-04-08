#ifndef Oversized_HPP
#define Oversized_HPP

#include <stdexcept>
#include <cstring>

class Oversized : public std::exception
{
private:
    /* data */
    char* m_msg; //cannot use const here coz we are using strcpy and also if we do then data cannot be change
public:
    Oversized(const char* msg) {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg,msg);
    }

    Oversized() = delete;
    Oversized(const Oversized&) = delete;
    Oversized(Oversized&&) = default;
    Oversized& operator=(const Oversized&) = delete;
    Oversized&& operator=(Oversized&&) = delete;


    ~Oversized() {
        delete []m_msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return m_msg;
    }
};

#endif // Oversized_HPP
