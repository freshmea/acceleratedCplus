#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, int> wordCount;
    string s;
    while(cin >> s){
//        s.erase(remove(s.begin(), s.end(), "\""), s.end());
        ++wordCount[s];
    }
    for(map<string, int>::const_iterator it = wordCount.cbegin(); it != wordCount.cend();++it)
        cout << it->first << " : " << it->second << ", ";
    cout << endl;
    return 0;
}