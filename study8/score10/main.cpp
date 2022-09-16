#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <map>
#include "student_info.h"
using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info student;

    while (student.read(cin) ) {
        students.push_back(student);
    }


//    std::sort(students.begin(), students.end(), Student_info::compare_student);

    int lineCount = 0;
    for (auto & sMember : students){
        cout <<sMember.name() << " : ";

        string s;
        char buf[6];
        sprintf(buf, "%.2f", sMember.grade());
        s = buf;

        cout << s <<'\t';
        ++lineCount;
        if (!(lineCount%5)) cout << endl;
    }


    return 0;
}