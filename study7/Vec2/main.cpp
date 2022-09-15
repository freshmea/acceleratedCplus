
#include <iostream>
#include "Vec.h"
using std::cout;
using std::endl;

int main()
{
    Vec<int> v1;
    Vec<int> v2(100);

    cout << " v2 " <<" : ";
    for(auto i : v2)
        cout << i << ", ";
    cout << endl;

    for(int i=0;i<20;i++)
        v1.push_back(i);
    cout << " v1 " <<" : ";
    for(auto i : v1)
        cout << i << ", ";
    cout << endl;

    Vec<int> v3(v1);
    cout << " v3 " <<" : ";
    for(auto i : v3)
        cout << i << ", ";
    cout << endl;

    v2 = v1;
//    std::copy(v1.cbegin(), v1.cend(), std::ostream_iterator<int>(cout, ))
    cout << " v2 " <<" : ";
    for(auto i : v2)
        cout << i << ", ";
    cout << endl;

    v2.erase(v2.begin()+3, v2.begin()+5);
    v2.push_back(1);
    cout << " v2 " <<" : ";
    for(auto i : v2)
        cout << i << ", ";
    cout << endl;
    v2.clear();

    return 0;
}