#include <iostream>
#include "Vec.h"
#include "Str.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
    Str str;
    Str str2 = "hello";
    Str str3("hello", "hello"+5);
    Str str4(5, '*');
    Vec<Str> a;
    str4 = str4+str2;
    str4 += "*****";
    cout << str << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
//    cin >> str ;
    str = str2 + str2;
    cout << str;

    for (Str::size_type i=0; i != str.size(); ++i){
        cout << str[i] << endl;
    }
    return 0;
}