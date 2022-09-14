#ifndef ACCELERATEDCPLUS_STUDENT_INFO_P_H
#define ACCELERATEDCPLUS_STUDENT_INFO_P_H
#include <iostream>
#include <string>

class Student_info_p;
bool compare(const Student_info_p& s1, const Student_info_p& s2);

class Student_info_p{
private:
    std::string name_;
    double midterm_;
    double finalterm_;
public:
    Student_info_p();
    explicit Student_info_p(std::istream& in);
    std::istream& read(std::istream& in);
    std::string name() const;
    double grade() const;
    bool isPass() const;
};

#endif //ACCELERATEDCPLUS_STUDENT_INFO_P_H
