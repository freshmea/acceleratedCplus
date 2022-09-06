#include <iostream>
#include "student_info.h"
#include "median.h"

static std::istream& read_hw(std::istream& in, Student_info& s)
{
    if(in) {
        s.homeworks.clear();
        double homework;
        while (in >> homework) {
            s.homeworks.push_back(homework);
        }
        in.clear();
    }
    return in;
}

 std::istream& read(std::istream& in, Student_info& s){
    s.sum =0;
    in >> s.name >> s.midterm >> s.finalterm;
    s.sum += s.midterm*0.2+s.finalterm*0.4;
    ::read_hw(in, s);
    if(s.homeworks.empty()){
        throw std::domain_error("homework vector is empty");
    }
    s.sum += 0.4*::median(s.homeworks);
    return in;
}

bool Student_info::operator<(const Student_info &rhs) const {
    return this->name < rhs.name;
}