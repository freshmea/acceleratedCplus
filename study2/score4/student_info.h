#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
#include <vector>
struct Student_info{
    std::string name;
    double midterm{};
    double finalterm{};
    std::vector<double> homeworks;

    bool operator<(const Student_info& rhs) const;
};

std::istream& read(std::istream& in, Student_info& s);
double grade(const Student_info& s);
#endif
