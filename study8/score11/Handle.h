//
// Created by aa on 22. 9. 16.
//

#ifndef ACCELERATEDCPLUS_HANDLE_H
#define ACCELERATEDCPLUS_HANDLE_H
#include <stdexcept>

template <typename T>
class Handle {
public:
    Handle(): p(0), pRc(new std::size_t(1)) {}
    Handle(T *p2):p(p2), pRc(new std::size_t(1)) { }
    Handle(const Handle<T>& rhs);
    ~Handle();

    Handle<T>& operator=(const Handle<T>& rhs);

    operator bool() const;
    T& operator *() const;
    T* operator ->() const;

private:
    T *p;
    std::size_t *pRc;
};

template <typename T>
Handle<T>::Handle(const Handle<T>& rhs)
: p(rhs.p), pRc(rhs.pRc)
{
    ++(*pRc);
}

template <typename T>
Handle<T>::~Handle()
{
    --(*pRc);
    if (*pRc == 0)
        delete p;
}

template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs)
{
    if (this != &rhs){
        --(*pRc);
        if ((*pRc) == 0 )
            delete p;

        p =rhs.p;
        pRc = rhs.pRc;
        ++(*pRc);
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
