#ifndef EmptyContainer_HPP
#define EmptyContainer_HPP

#include <stdexcept>
#include <cstring>

class EmptyContainer : public std::exception
{
private:
    /* data */
    char* m_msg; //cannot use const here coz we are using strcpy and also if we do then data cannot be change
public:
    EmptyContainer(const char* msg) {
        m_msg = new char[strlen(msg) + 1];
        strcpy(m_msg,msg);
    }

    EmptyContainer() = delete;
    EmptyContainer(const EmptyContainer&) = delete;
    EmptyContainer(EmptyContainer&&) = default;
    EmptyContainer& operator=(const EmptyContainer&) = delete;
    EmptyContainer&& operator=(EmptyContainer&&) = delete;


    ~EmptyContainer() {
        delete []m_msg;
    }


    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return m_msg;
    }
};

#endif // EmptyContainer_HPP
