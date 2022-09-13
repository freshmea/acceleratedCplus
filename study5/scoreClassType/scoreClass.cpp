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
    map<char, vector<Student_info> > gradeMap;
    string::size_type maxLen = 0;

    try {
        while (student.read(cin)) {
            maxLen = max(maxLen, student.name().size());
            students.push_back(student);
        }
    } catch (domain_error e){
        cout <<e.what() <<endl;
    }


    sort(students.begin(), students.end());
    for(auto & sMember : students){
        gradeMap[sMember.fgrade()].push_back(sMember);
    }
    int lineCount = 0;
    for (auto & sMember : students){
        streamsize prec = cout.precision();
        cout << string(maxLen +1 -sMember.name().size(), ' ') <<sMember.name() << " : ";

        string s;
        char buf[6];
        sprintf(buf, "%.2f", sMember.grade());
        s = buf;

        cout << setprecision(4) << s << setprecision(prec)<<'\t';
        ++lineCount;
        if (!(lineCount%5)) cout << endl;
    }

    for(auto const & itGradeMap : gradeMap){
        cout << itGradeMap.first << " | Count : " << itGradeMap.second.size() << " | ";
        for(auto gradeStudentVector=itGradeMap.second.cbegin();gradeStudentVector !=itGradeMap.second.cend(); ++gradeStudentVector)
            cout << gradeStudentVector->name() << " : " << gradeStudentVector->grade() << ((itGradeMap.second.cend() == gradeStudentVector+1) ? "" : " , ");
        cout << endl;
    }

    for (auto & sMember : students){
        streamsize prec = cout.precision();
        cout << string(maxLen +1 -sMember.name().size(), ' ') <<sMember.name() << " : ";
        cout << setprecision(4) << sMember.finalGrade() << setprecision(prec)<<'\t';
        ++lineCount;
        if (!(lineCount%5)) cout << endl;
    }
    return 0;
}