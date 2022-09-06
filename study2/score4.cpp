#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
using namespace std;

struct Student_info{
    string name;
    double midterm{};
    double finalterm{};
    vector<double> homeworks;
};

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

istream& read(istream& in, Student_info& s){
    in >> s.name >> s.midterm >> s. finalterm;

    ::read_hw(in, s.homeworks);
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
    return  0.2 * midterm +0.4* finalterm + 0.4 * median;
}

double grade(double midterm, double finalterm, const vector<double>& hws) {
    if(hws.empty()){
        throw domain_error("homework vector is empty");
    }
    double homework = ::median(hws);
    return ::grade(midterm, finalterm, homework);
}

double grade(const Student_info& s){
    return ::grade(s.midterm, s.finalterm, s.homeworks);
}

int main()
{
    vector<Student_info> students;

    Student_info student;
    while(read(cin, student)){
        students.push_back(student);
    }

    for (auto &student: students)
        try {
            double finalScore = ::grade(student);
            auto prec = cout.precision();   // std::streamsize
            cout << student.name << " : " << std::setprecision(5) << finalScore << std::setprecision(prec) << endl;
        } catch (domain_error &e) {
            std::cerr << e.what() << endl;
            return 1;
        }


    return 0;
}