//
// Created by aa on 22. 9. 16.
//

#ifndef ACCELERATEDCPLUS_HANDLE_H
#define ACCELERATEDCPLUS_HANDLE_H
#include <stdexcept>

template <typename T>
class Handle {
public:
    Handle(): p(0) {}
    Handle(T *p2):p(p2) {}
    Handle(const Handle<T>& rhs);
    ~Handle(){delete p;}

    Handle<T>& operator=(const Handle<T>& rhs);

    operator bool() const;
    T& operator *() const;
    T* operator ->() const;

private:
    T *p;
};

template <typename T>
Handle<T>::Handle(const Handle<T>& rhs)
{
    if (rhs.p )
        p = rhs.p->clone();
    else p = 0;
}

template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs)
{
    if (this != &rhs){
        delete p;
        if (rhs.p )
            p = rhs.p->clone();
        else p = 0;
    }
    return *this;
}

template <typename T>
Handle<T>::operator bool() const
{
    return p;
}


template <typename T>
T& Handle<T>::operator *() const
{
    if (p )
        return *p;
    else
        throw std::runtime_error("uninitialized");
}


template <typename T>
T* Handle<T>::operator ->() const
{
    if (p )
        return p;
    else
        throw std::runtime_error("uninitialized");
}

#endif //ACCELERATEDCPLUS_HANDLE_H
