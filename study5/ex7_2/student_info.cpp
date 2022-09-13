#include <iostream>
#include <vector>
#include "student_info.h"
#include "median.h"

std::istream& read(std::istream& in, Student_info& s){
    s.grade =0;
    int midterm;
    int finalterm;
    in >> s.name >> midterm >> finalterm;
    s.grade += midterm*0.2+finalterm*0.4;
    std::vector<double> homeworks;

    if(in) {
        homeworks.clear();
        double homework;
        while (in >> homework) {
            homeworks.push_back(homework);
        }
        in.clear();
    } else return in;
    s.grade += 0.4*::median(homeworks);
    return in;
}

bool Student_info::operator<(const Student_info &rhs) const {
    return this->name < rhs.name;
}