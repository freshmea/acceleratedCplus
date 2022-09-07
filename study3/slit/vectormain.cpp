#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(const string& s){
    vector<string> words;

    string::size_type i = 0;
    while (i != s.size()){
        while(i != s.size() && isspace(s[i])){
            ++i;
        }

        string::size_type j = i ;
        while (j != s.size() && !isspace(s[j])){
            ++j;
        }
        if (i != j){
            words.push_back(string(s.substr(i, j-i)));
        }
    }
    return words;
}

int main()
{
    string s;
    vector<string> words;
    while (getline(cin, s)){
        cout << s;
        words = ::split(s);
    }

    for(auto i: words)
        cout << i << endl;
    return 0;
}