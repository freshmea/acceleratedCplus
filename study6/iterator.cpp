#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "algorithm2.h"
#include <string>

using namespace std;

template <typename S>
bool compare(S a)
{
    return a > 300;
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
    cout << equal2(v.begin(), v.end(), v2.begin()) << endl;
    cout << *find2(v.begin(), v.end(), 32) << endl;
    cout << *find_if2(v.begin(), v.end(), compare<int>) << endl;
    cout << "copy" << endl;

    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    copy2(v.begin(), v.begin()+3, v2.begin());
    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    transform2(v.begin(), v.end(), v2.begin(), mius100);
    for (auto i : v2)
        cout << i << " ";
    cout << endl;
    return 0;
}