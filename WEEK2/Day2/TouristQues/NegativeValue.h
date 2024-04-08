#ifndef NegativeValue_HPP
#define NegativeValue_HPP

#include <stdexcept>
#include <cstring>

class NegativeValue : public std::exception
{
private:
    /* data */
    char* m_msg; //cannot use const here coz we are using strcpy and also if we do then data cannot be change
public:
    NegativeValue(const char* msg) {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg,msg);
    }

    NegativeValue() = delete;
    NegativeValue(const NegativeValue&) = delete;
    NegativeValue(NegativeValue&&) = default;
    NegativeValue& operator=(const NegativeValue&) = delete;
    NegativeValue&& operator=(NegativeValue&&) = delete;


    ~NegativeValue() {
        delete []m_msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return m_msg;
    }
};

#endif // NegativeValue_HPP
