#ifndef ACCELERATEDCPLUS_STR_H
#define ACCELERATEDCPLUS_STR_H
#include "Vec.h"
#include <iostream>
#include <cstring>
#include <algorithm>

class Str{
friend std::ostream& operator<<(std::ostream& out, const Str& rhs);
friend std::istream& operator>>(std::istream& in, Str& rhs);

public:
    typedef Vec<char>::size_type size_type;

    Str();
    Str(const char *s);
    Str(size_type n, char c);

    template < typename In>
    Str(In b, In e);

    char& operator[](int index);
    const char& operator[](int  index) const;

    Str& operator+=(const Str& rhs);
    const Str operator+(const Str& rhs) const;
    size_type size() const;

private:
    Vec<char> data;
};

template < typename In>
Str::Str(In b, In e)
{
    std::copy(b, e, std::back_inserter(data));
}


#endif //ACCELERATEDCPLUS_STR_H
