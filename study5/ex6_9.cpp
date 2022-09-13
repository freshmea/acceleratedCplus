#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<string> s1= {"Knocking", "on the",  "heaven's ",  "door"};
    string inString ;
//    while(cin >> inString){
//        s1.push_back(inString);
//    }
    for(auto s : s1)
        cout << s << ", ";
    cout << endl;
    string plusString;
    plusString = accumulate(s1.begin(), s1.end(), plusString);
    cout << plusString << endl;
    return 0;
}