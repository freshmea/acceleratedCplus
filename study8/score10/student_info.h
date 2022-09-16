#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
#include <vector>
#include "Core.h"
#include "Grad.h"
#include "Handle.h"

class Student_info;


class Student_info{
private:
    Core *pc;
    Handle<Core> h;

public:
    static bool compare_student(const Student_info& s1, const Student_info& s2);
    Student_info();
    Student_info(std::istream& in);
    Student_info(const Student_info& rhs);

    Student_info& operator=(const Student_info& rhs);
    std::istream& read(std::istream& in);
    std::string name() const;
    double grade() const;

};


#endif
