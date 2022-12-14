#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include "student_info.h"
using namespace std;

double fgrade(Student_info s)
{
    return s.grade;
}
//void extract_fails(vector<Student_info>& students, vector<Student_info>& fail) {
//    vector<Student_info> pass;
//    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i){
//        if(fgrade(students[i]) < 60) {
//            fail.push_back(students[i]);
//        } else {
//            pass.push_back(students[i]);
//        }
//    }
//    students = pass;
//}

void extract_fails(vector<Student_info>& pass, vector<Student_info>& fail) {
    for(vector<Student_info>::size_type i = 0; i != pass.size();i++){
        if(fgrade(pass[i]) < 60) {
            fail.push_back(pass[i]);
            pass.erase(pass.begin() + i);
            --i;
        }
    }
}
//void extract_fails(vector<Student_info>& pass, vector<Student_info>& fail) {
//    for(vector<Student_info>::iterator i = pass.begin(); i != pass.end();++i){
//        if(fgrade(*i) < 60) {
//            fail.push_back(*i);
//            i = pass.erase(i);      // erase 는 지운 다음 위치를 반환 한다.
//        }
//    }
//}

int main()
{
    vector<Student_info> students;
    Student_info student;

    while(read(cin, student)){
        students.push_back(student);
    }

    vector<Student_info> passList= students;
    vector<Student_info> failList;

    ::extract_fails(passList, failList);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        cout << students[i].name << " : " << students[i].grade << endl;
    }
    vector<Student_info>::const_iterator  it;
    for( it = students.cbegin();it != students.cend(); ++it){
        cout << (*it).name << " : " << (*it).grade << endl;
    }
    auto it2 =students.begin();
    cout << (*it2).name;

    return 0;
}