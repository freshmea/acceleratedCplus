//
// Created by aa on 22. 9. 14.
//
#include <iostream>
#include "Vec.h"
using std::cout;
using std::endl;

int main()
{
    Vec<int> v1;
    Vec<int> v2(100);

    cout << " v2 " <<endl;
    for(auto i : v2)
        cout << i << " ";
    cout << endl;

    for(int i=0;i<20;i++)
        v1.push_back(i);
    cout << " v1 " <<endl;
    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    Vec<int> v3(v1);


    return 0;
}