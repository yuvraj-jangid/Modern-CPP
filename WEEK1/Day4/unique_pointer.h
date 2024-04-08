#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
class unique_pointer
{
private:
    T* m_ptr;

public:
    unique_pointer(T* m_ptr): m_ptr {ptr}{
        ptr = nullptr;
    }

    unique_pointer(const T*&) = delete;
    unique_pointer& operator=(const T*&) = delete;
    

    unique_pointer(const T*&&) = default;
    unique_pointer& operator=(const T*&&) = default;

    void Release(){delete m_ptr; m_ptr = nullptr} // manually delete

    ~unique_pointer() {delete m_ptr; m_ptr = nullptr} // delete using destructor

};


#endif // UNIQUE_POINTER_H
