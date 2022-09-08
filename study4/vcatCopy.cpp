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

//    for(const auto & it : bottom){
//        result.push_back(it);
//    }
    copy(bottom.cbegin(), bottom.cend(), std::back_inserter(result));
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

vector<string> center(const vector<string>& words){
    vector<string> s;
    string::size_type maxLen = width(words);

    for(vector<string>::const_iterator it = words.cbegin(); it != words.cend(); ++it){
        s.push_back(string((maxLen - it->size())/2, ' ') + *it + string((maxLen- it->size())/2+(maxLen- it->size())%2, ' '));
    }
    return s;
}

int main()
{
    string s;
    while (std::getline(cin, s)){
        vector<string> words = ::split(s);
        vector<string> frameWords = frame(words);

        words = vcat(words, frameWords);
//        words = hcat(words, frameWords);
//        words = frame(center(words));
        for(const auto & word : words)
            cout << word <<endl;

    }
    return 0;
}