#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, ", "));

    return 0;
}