#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

bool not_space(string::value_type c){
    return !isspace(c);
}
bool space(string::value_type c){
    return isspace(c);
}

vector<string> split(const string& s){
    vector<string> result;
    string::const_iterator it = s.cbegin();
    while (it != s.cend()){
        it = find_if(it, s.cend(), not_space);
        string::const_iterator it2 = it;
        it2 = find_if(it, s.cend(), space);

        if (it != s.cend()){
            string s1(it, it2);
            result.push_back(s1);
        }
        it = it2;
    }
    return result;
}

int main()
{
    map<string, vector<int> > wordLine;
    int line = 1;
    string s;
    while(getline(cin, s)){
        cout << s << endl;
        ++line;
        vector<string> splitWord;
        splitWord = split(s);
        for(auto word : splitWord){
            wordLine[word].push_back(line);
        }
    }
    for(auto it = wordLine.cbegin(); it != wordLine.cend();++it) {
        cout << it->first << " : " ;
        for(auto it2: it->second )
            cout << it2 << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}