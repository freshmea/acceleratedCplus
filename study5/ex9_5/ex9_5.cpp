#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "student_info.h"
using namespace std;

int main()
{
    vector<Student_info> students;
    Student_info student;
    string::size_type maxLen = 0;

    try {
        while (student.read(cin)) {
            maxLen = max(maxLen, student.name().size());
            students.push_back(student);
        }
    } catch (domain_error e){
        cout <<e.what() <<endl;
    }

    int lineCount = 0;
    for (auto & sMember : students){
        streamsize prec = cout.precision();
        cout << string(maxLen +1 -sMember.name().size(), ' ') <<sMember.name() << " : ";
        cout << setprecision(4) << sMember.finalGrade() << setprecision(prec)<<'\t';
        ++lineCount;
        if (!(lineCount%5)) cout << endl;
    }
    return 0;
}