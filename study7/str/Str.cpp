#include "Str.h"

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

