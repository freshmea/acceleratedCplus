#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "student_info.h"
using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info student;
    auto maxLen = student.name.size();
    while(read(cin, student)){
        students.push_back(student);
        maxLen = max(maxLen, student.name.size());
    }

    sort(students.begin(), students.end());

    for (int i=0;i<students.size();i++) {
        try {
            int pad = maxLen - students[i].name.size() + 1;
            auto prec = cout.precision();   // std::streamsize
            cout << students[i].name << string(pad, ' ') << " : " << std::setprecision(5) << students[i].sum << std::setprecision(prec) << endl;
        } catch (domain_error &e) {
            std::cerr << e.what() << endl;
            return 1;
        }
    }


    return 0;
}