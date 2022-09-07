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
            i = j;
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

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> result = top;

    for(vector<string>::const_iterator it = bottom.cbegin(); it != bottom.cend(); ++it){
        result.push_back(*it);
    }

    return result;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> result;

    vector<string>::size_type i =0;
    vector<string>::size_type j =0;

    string::size_type pad = ::width(left);

    while( i != left.size() || j != right.size()){
        string s;
        if (i != left.size()){
            s = left[i];
            ++i;
        }
        s += string(pad - s.size(), ' ');

        if ( j != right.size()){
            s += right[j];
            ++j;
        }
        result.push_back(s);
    }
    return result;
}
int main()
{
    string s;
    while (std::getline(cin, s)){
        vector<string> words = ::split(s);
        vector<string> frameWords = frame(words);

//        words = vcat(words, frameWords);
        words = hcat(words, frameWords);
        for(const auto & word : words)
            cout << word <<endl;
    }
    return 0;
}