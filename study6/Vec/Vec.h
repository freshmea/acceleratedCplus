//
// Created by aa on 22. 9. 14.
//

#ifndef ACCELERATEDCPLUS_VEC_H
#define ACCELERATEDCPLUS_VEC_H

template<typename T>
class Vec{
private:
    T* data_;
    T* limit_;
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T value_type;
    typedef size_t size_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::ptrdiff_t difference_type;

    Vec();
    explicit Vec(int size, const T& val = T());
};

template<typename T>
Vec<T>::Vec()
{
    create();
}

template<typename T>
Vec<T>::Vec(int size, const T& value)
{
    create(size, value);
}


#endif //ACCELERATEDCPLUS_VEC_H
