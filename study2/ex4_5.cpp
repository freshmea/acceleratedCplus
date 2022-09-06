#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct WordCount {
    string word;
    int count;
};

std::istream& read(std::istream& in, vector<WordCount>& wc) {
    if (in) {
        wc.clear();

        string word;
        while (cin >> word) {
            int i;
            for (i = 0; i != wc.size(); ++i) {
                if (word == wc[i].word)
                    break;
            }

            if (i == wc.size()) {
                WordCount w;
                w.word = word;
                w.count = 1;
                wc.push_back(w);
            } else {
                ++wc[i].count;
            }
        }
        in.clear();
    }
    return in;
}
int main()
{
    vector<WordCount> wordCount;
    read(cin, wordCount);

    for(int i=0; i != wordCount.size();++i){
        cout << wordCount[i].word << " : " << wordCount[i].count << endl;
    }
    return 0;
}