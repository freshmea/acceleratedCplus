#include "Str.h"

std::ostream& operator<<(std::ostream& out, const Str& rhs)
{
    for (Str::size_type i = 0; i != rhs.data.size(); ++i)
        out << rhs.data[i];
    return out;
}
std::istream& operator>>(std::istream& in, Str& rhs)
{
    rhs.data.clear();

    char c;
    while (in.get(c) && isspace(c))
        ;
    rhs.data.push_back(c);

    if(in ){
        while(in.get(c) && !std::isspace(c)){
            rhs.data.push_back(c);
        }
        if(in ){
            in.unget();
        }
    }
    return in;
}
Str::Str()
{}
Str::Str(const char *s)
{
//    for (int i = 0 ; i < strlen(s);++i)
//        data.push_back(s[i]);
    std::copy(s, s + strlen(s), std::back_inserter(data));
}
Str::Str(size_type n, char c)
: data(n, c)
{

}

char& Str::operator[](int index)
{
    return data[index];
}

const char& Str::operator[](int index) const
{
    return data[index];
}

Str& Str::operator+=(const Str& rhs)
{
    Str tmp(rhs);
    std::copy(tmp.data.cbegin(), tmp.data.cend(), std::back_inserter(data));
    return *this;
}
const Str Str::operator+(const Str& rhs) const
{
    Str result = *this;
    result += rhs;

    return result;
}

Str::size_type Str::size() const
{
    return data.size();
}
