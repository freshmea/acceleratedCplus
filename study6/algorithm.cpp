#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "algorithm2.h"

using namespace std;


template <typename T>
bool compare(const T& val)
{
    return val > 300;
}

int mius100(const int & a)
{
    return a-100;
}

int main()
{
    vector<int> v;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, ", "));

    vector<int> v2 = v;
    v2[1] = 0;
    cout << endl;
    cout << aiot::equal(v.begin(), v.end(), v2.begin()) << endl;
    cout << *aiot::find(v.begin(), v.end(), 32) << endl;
    auto it2 = aiot::find_if(v.begin(), v.end(), compare<int>);
    cout << *it2 << endl;
    cout << "copy" << endl;

    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    aiot::copy(v.begin(), v.begin()+3, v2.begin());
    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    aiot::transform(v.begin(), v.end(), v2.begin(), mius100);
    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    v.erase(aiot::remove(v.begin(), v.end(), 41), v.end());
    for (int & i : v)
        cout << i << " ";
    cout << endl;

//    copy(v.begin, v.end())
    return 0;
}