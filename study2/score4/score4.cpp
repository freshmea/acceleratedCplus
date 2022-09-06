#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include "student_info.h"
using namespace std;

bool compare(const Student_info& s1, const Student_info& s2){
    return s1.name < s2.name;
}

int main()
{
    vector<Student_info> students;
    Student_info student;
    auto maxLen = student.name.size();
    while(read(cin, student)){
        students.push_back(student);
        maxLen = max(maxLen, student.name.size());
    }

//    sort(students.begin(), students.end(), compare);
    sort(students.begin(), students.end());
    for (int i=0;i<students.size();i++) {
        try {
            double finalScore = ::grade(students[i]);

            int pad = maxLen - students[i].name.size() + 1;
            auto prec = cout.precision();   // std::streamsize
            cout << students[i].name << string(pad, ' ') << " : " << std::setprecision(5) << finalScore << std::setprecision(prec) << endl;
        } catch (domain_error &e) {
            std::cerr << e.what() << endl;
            return 1;
        }
    }


    return 0;
}