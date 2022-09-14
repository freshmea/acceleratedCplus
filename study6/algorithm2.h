//
// Created by aa on 22. 9. 14.
//

#ifndef ACCELERATEDCPLUS_ALGORITHM2_H
#define ACCELERATEDCPLUS_ALGORITHM2_H
#include <iterator>

template <typename T>
bool equal2(T b, T e, T d)
{
    if (b == e )
        return true;
    if(*b != *d)
        return false;
    ++b;
    ++d;
    return equal2(b, e, d);
}

template <typename T, typename X >
T find2(T b, T e, const X& d)
{
    if (b == e || *b == d)
        return b;
    ++b;
    return find2(b, e, d);
}

template <typename T, typename F>
T find_if2(T b, T e,F f)
{
    if (f(*b))
        return b;
    ++b;
    return find_if2(b, e, f);
}

template <typename I, typename O>
O copy2(I b, I e,O d)
{
    while( b != e)
        *d++ = *b++;
    return d;
}

template<typename T, typename D, typename F>
D transform2(T b, T e,D d, F f)
{
    while(b == e) {
        *d++=f(*b);
        ++b;
    }
    return d;
}
#endif //ACCELERATEDCPLUS_ALGORITHM2_H
