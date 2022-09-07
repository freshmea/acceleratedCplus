#include <iostream>
#include <string>
#include <list>
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

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}
//void extract_fails(list<Student_info>& students, list<Student_info>& fail) {
//    list<Student_info> pass;
//    for(list<Student_info>::size_type i = 0; i != students.size(); ++i){
//        if(fgrade(students[i]) < 60) {
//            fail.push_back(students[i]);
//        } else {
//            pass.push_back(students[i]);
//        }
//    }
//    students = pass;
//}

//void extract_fails(list<Student_info>& pass, list<Student_info>& fail) {
//    for(list<Student_info>::size_type i = 0; i != pass.size();){
//        if(fgrade(pass[i]) < 60) {
//            fail.push_back(pass[i]);
//            pass.erase(pass.begin() + i);
//        } else{
//            ++i;
//        }
//    }
//}

void extract_fails(list<Student_info>& pass, list<Student_info>& fail) {
    for(list<Student_info>::iterator i = pass.begin(); i != pass.end();++i){
        if(fgrade(*i) < 60) {
            fail.push_back(*i);
            i = pass.erase(i);      // erase 는 지운 다음 위치를 반환 한다.
        }
    }
}

int main()
{
    list<Student_info> students;
    Student_info student;

    while(read(cin, student)){
        students.push_back(student);
    }

    list<Student_info> passList= students;
    list<Student_info> failList;

    ::extract_fails(passList, failList);

//    for (list<Student_info>::size_type i = 0; i != students.size(); ++i){
//        cout << students[i].name << " : " << students[i].grade << endl;
//    }         // 리스트에서는 안됨.
    // std::sort(students.begin(), students.end(), compare); 링크드 리스트는 알고리즘 소트를 할 수 없다. 멤버안에 정의 되어 있다.
    students.sort(compare);

    list<Student_info>::const_iterator  it;
    for( it = students.cbegin();it != students.cend(); ++it){
        cout << (*it).name << " : " << (*it).grade << endl;
    }
    auto it2 =students.begin();
    cout << (*it2).name;

    return 0;
}