#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
#include <vector>
struct Student_info{
    std::string name;
    double sum;
    bool operator<(const Student_info& rhs) const;
};

std::istream& read(std::istream& in, Student_info& s);
#endif
