#include <iostream>
#include "Vec.h"
#include "Str.h"
using std::cout;
int main()
{
    Str str;
    Str str2 = "hello";
    Str str3("hello", "hello"+5);
    Str str4(5, '*');
    Vec<Str> a;
    return 0;
}