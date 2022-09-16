#include <iostream>
#include <vector>
#include "student_info.h"

bool Student_info::compare_student(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}

Student_info::Student_info(): pc(0)
{

}

Student_info::Student_info(std::istream& in ): pc(0)
{
    read(in);
}

Student_info::Student_info(const Student_info& rhs)
{
    //pc = new ???;
    if(rhs.pc ) {
        pc = rhs.pc->clone();
    }
}

Student_info::~Student_info()
{
    delete pc;
}

Student_info& Student_info::operator=(const Student_info& rhs)
{
    if(this != &rhs) {
        delete pc;
        pc = rhs.pc->clone();
    }
    return *this;
}

std::istream& Student_info::read(std::istream& in)
{
    if (pc ){
        delete pc;
    }
    char ch;
    in >> ch;
    if (ch =='U'){
        pc = new Core(in);
    } else{
        pc = new Grad(in);
    }
    return in;
}

std::string Student_info::name() const
{
    if(pc ) {
        return pc->name();
    } else {
        throw std::runtime_error("empty student");
    }
}

double Student_info::grade() const
{
    if(pc ) {
        return pc->grade();
    } else {
        throw std::runtime_error("empty student");
    }
}