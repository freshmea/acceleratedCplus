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

string::size_type width(const vector<string>& words){
    string::size_type maxLen = 0;
    for(vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it){
        maxLen = max(maxLen, it->size());
    }
    return maxLen;
}

vector<string> frame(const vector<string> words){
    vector<string> frameWords;

    string::size_type maxLen = width(words);

    string boarder(maxLen + 4, '*');
    frameWords.push_back(boarder);
    for(vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it){
        frameWords.push_back("* "+ *it + string(maxLen- it->size(), ' ')+" *");
    }
    frameWords.push_back(boarder);
    return frameWords;
}

int main()
{
    string s;
    vector<string> words;
    while (std::getline(cin, s)){
        cout << s;
        words = ::split(s);
        words = frame(words);
        for(auto i: words)
            cout << i << endl;
    }
    return 0;
}