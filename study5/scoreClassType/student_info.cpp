#include <iostream>
#include <vector>
#include "student_info.h"
#include "median.h"

std::istream& Student_info::read(std::istream& in){
    _grade =0;

    in >> _name >> _midterm >> _finalterm;
    _grade += _midterm*0.2+_finalterm*0.4;

    if(in) {
        _homeworks.clear();
        double homework;
        while (in >> homework) {
            _homeworks.push_back(homework);
        }
        in.clear();
    } else return in;
    _grade += 0.4*::median(_homeworks);
    char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
    _fgrade = grades[static_cast<int>(_grade/10)];
    return in;
}


bool Student_info::operator<(const Student_info &rhs) const {
    return this->_name < rhs._name;
}