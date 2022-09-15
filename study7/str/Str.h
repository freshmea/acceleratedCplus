#ifndef ACCELERATEDCPLUS_STR_H
#define ACCELERATEDCPLUS_STR_H
#include "Vec.h"
#include <cstring>
#include <algorithm>


class Str{
public:
    typedef Vec<char>::size_type size_type;

    Str();
    Str(const char *s);
    Str(size_type n, char c);

    template < typename In>
    Str(In b, In e);
private:
    Vec<char> data;
};

template < typename In>
Str::Str(In b, In e)
{
    std::copy(b, e, std::back_inserter(data));
}


#endif //ACCELERATEDCPLUS_STR_H
