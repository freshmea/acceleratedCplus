#ifndef ACCELERATEDCPLUS_VEC_H
#define ACCELERATEDCPLUS_VEC_H
#include <memory>
#include <algorithm>

template<typename T>
class Vec{
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
    Vec(const Vec<T>& rhs);
    ~Vec();
    Vec<T>& operator=(const Vec<T>& rhs);

    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const {return data[index]; }

    size_type size() const { return avail - data; }
    iterator begin() { return data; }
    iterator end() { return avail; }
    const_iterator cbegin() const { return data; }
    const_iterator cend() const { return avail; }
    void push_back(const T& val);
    iterator erase(iterator b, iterator e);
    void clear();

private:
    T* data;
    T* avail;
    T* limit;
    std::allocator<T> alloc;

    void create();
    void create(size_type n, const T& value);
    void create(const_iterator begin, const_iterator end);

    void uncreate();

    void grow();
    void unchecked_append(const T& rhs);
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

template<typename T>
Vec<T>::Vec(const Vec<T>& rhs)
{
    create(rhs.cbegin(), rhs.cend());
}

template<typename T>
Vec<T>::~Vec()
{
    uncreate();
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
    if(this != &rhs){
        uncreate();
        create(rhs.cbegin(), rhs.cend());
    }
    return *this;
}

template <typename T>
void Vec<T>::push_back(const T& val)
{
    if (avail == limit)
        grow();
    unchecked_append(val);
}

template<typename T>
typename Vec<T>::iterator Vec<T>::erase(iterator b, iterator e)
{
    if(data == b && avail == e){
        uncreate();
    }else {
        avail = std::copy(e + 1, avail, b);
    }
    return avail;
}
template<typename T>
void Vec<T>::clear()
{
    uncreate();
}

template <typename T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template<typename T>
void Vec<T>::create(size_type size, const T& value)
{
    data = alloc.allocate(size);
    limit = avail = data + size;
    std::uninitialized_fill(data, data+size, value);
}

template<typename T>
void Vec<T>::create(const_iterator begin, const_iterator end)
{
    data = alloc.allocate(end - begin);
    limit = avail = std::uninitialized_copy(begin, end, data);
}

template<typename T>
void Vec<T>::uncreate()
{
    if (data ){
        iterator it = avail;
        while (it != data){
            alloc.destroy(it);
            --it;
        }
        alloc.deallocate(data, limit - data);
    }

    data = avail = limit = 0;
}

template <typename T>
void Vec<T>::grow()
{
    size_type len = std::max(2*(limit - data), difference_type(1));

    iterator b = alloc.allocate(len);
    iterator e = std::uninitialized_copy(data, avail, b);
    uncreate();
    data = b;
    avail = e;
    limit = b + len;
}

template <typename T>
void Vec<T>::unchecked_append(const T &rhs)
{
    alloc.construct(avail, rhs);
    ++avail;
}
#endif //ACCELERATEDCPLUS_VEC_H
