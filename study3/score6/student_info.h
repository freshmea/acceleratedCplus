#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
struct Student_info{
    std::string name;
    double grade;
    bool operator<(const Student_info& rhs) const;
};

std::istream& read(std::istream& in, Student_info& s);
#endif
