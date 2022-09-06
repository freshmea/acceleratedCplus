#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
using namespace std;

istream& read_hw(istream& in, vector<double>& homeworks)
{
    if(in) {
        homeworks.clear();

        double homework;
        while (in >> homework) {
            homeworks.push_back(homework);
        }

        in.clear();
    }
    return in;
}

double median(const vector<double>& v) {
    if(v.empty()){
        throw domain_error("vector is empty");
    }
    vector<double> vec = v;
    sort(vec.begin(), vec.end());
    auto n = vec.size() / 2; // vector<double>::size_type
    return (vec.size() % 2) ? vec[n] : (vec[n] + vec[n - 1]) / 2;
}

double grade(double midterm, double finalterm, double median){
    return  0.211111 * midterm +0.4* finalterm + 0.4 * median;
}

double grade(double midterm, double finalterm, const vector<double>& hws) {
    if(hws.empty()){
        throw domain_error("homework vector is empty");
    }
    double homework = ::median(hws);
    return ::grade(midterm, finalterm, homework);
}

int main()
{
    string name;
    cin >> name;

    double midterm, finalterm;
    cin >> midterm >> finalterm;

    vector<double> homeworks;
    ::read_hw(cin, homeworks);
    try {
        double finalScore = ::grade(midterm, finalterm, homeworks);

        auto prec = cout.precision();   // std::streamsize
        cout << std::setprecision(5) << "finalScore is : " << finalScore << std::setprecision(prec) << endl;
    } catch (domain_error& e){
        std::cerr << e.what() << endl;
        return 1;
    }
    return 0;
}