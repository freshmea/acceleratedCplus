#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string name;
    cin >> name;

    double midterm, finalterm;
    cin >> midterm >> finalterm;
    double homework;

    vector<double> homeworks;
    while(cin>>homework){
        homeworks.push_back(homework);
    }
    std::sort(homeworks.begin(), homeworks.end());
    for(auto i : homeworks)
        cout << i << endl;

    auto n = homeworks.size()/2; // vector<double>::size_type
    double median = (homeworks.size() % 2) ? homeworks[n] : (homeworks[n]+homeworks[n-1])/2;
    double finalScore = 0.2 * midterm +0.4* finalterm + 0.4 * median;
    cout << "finalScore is : " << finalScore << endl;
    return 0;
}