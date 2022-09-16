#include <iostream>
#include <vector>
#include "student_info.h"

bool Student_info::compare_student(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}

Student_info::Student_info(){}

Student_info::Student_info(std::istream& in ){}

Student_info::Student_info(const Student_info& rhs)
{
    if(rhs.h ) {
        h = rhs.h->clone();
    }
}

Student_info& Student_info::operator=(const Student_info& rhs)
{
    if(this != &rhs) {
        if (rhs.h )
            h = rhs.h->clone();
    }
    return *this;
}

std::istream& Student_info::read(std::istream& in)
{
    char ch;
    in >> ch;
    if (ch =='U'){
        h = new Core(in);
    } else{
        h = new Grad(in);
    }
    return in;
}

std::string Student_info::name() const
{
    if(h ) {
        return h->name();
    } else {
        throw std::runtime_error("empty student");
    }
}

double Student_info::grade() const
{
    if(h ) {
        return h->grade();
    } else {
        throw std::runtime_error("empty student");
    }
}