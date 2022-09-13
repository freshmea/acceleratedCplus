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

char fgrade(Student_info s)
{
    if( s.grade >= 90){
        return 'A';
    } else if( s.grade >= 80){
        return 'B';
    } else if( s.grade >= 70){
        return 'C';
    } else if( s.grade >= 60){
        return 'D';
    } else {
        return 'F';
    }
}

int main()
{
    vector<Student_info> students;
    Student_info student;
    map<char, vector<Student_info> > gradeMap;

    while(read(cin, student)){
        students.push_back(student);
    }
    for(auto & sMember : students){
        gradeMap[fgrade(sMember)].push_back(sMember);
    }

//    for (auto & sMember : students){
//        cout << sMember.name << " : " << sMember.grade << endl;
//    }

    for(auto const & itGradeMap : gradeMap){
        cout << itGradeMap.first << " | Number : " << itGradeMap.second.size() << " | ";
//        for(auto const & gradeStudentVector : itGradeMap.second)
//            cout << gradeStudentVector.name << " : " << gradeStudentVector.grade << ((itGradeMap.second.back().name == gradeStudentVector.name) ? "" : " , ");
        for(std::vector<Student_info>::const_iterator gradeStudentVector=itGradeMap.second.cbegin();gradeStudentVector !=itGradeMap.second.cend(); ++gradeStudentVector)
            cout << gradeStudentVector->name << " : " << gradeStudentVector->grade << ((itGradeMap.second.cend() == gradeStudentVector+1) ? "" : " , ");
        cout << endl;
    }

    return 0;
}