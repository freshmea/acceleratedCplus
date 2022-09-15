//
// Created by aa on 22. 9. 14.
//
#include <iostream>
#include "Vec.h"
#include <string>
using std::cout;
using std::endl;

int main()
{
    Vec<int> v1;
    Vec<int> v2(100);
    Vec<std::string> v3;

    cout << " v1 " <<endl;
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    for(int i=0;i<50;i++)
        v1.push_back(i);

    cout << " v1 " <<endl;
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    v3.push_back("hi there");
    cout << v3[0];
    return 0;
}