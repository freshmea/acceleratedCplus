#include "student_info_p.h"

bool compare(const Student_info_p& s1, const Student_info_p& s2)
{
    return s1.name() < s2.name();
}

Student_info_p::Student_info_p()
:name_(""), midterm_(0.0), finalterm_(0.0){}

Student_info_p::Student_info_p(std::istream &in){
    read(in);
}
std::istream& Student_info_p::read(std::istream & in){
    in >> name_;
    if(in ){
        in >> midterm_ >> finalterm_;
    }
    return in;
}

std::string Student_info_p::name() const
{
    return name_;
}

double Student_info_p::grade() const{
    return (midterm_ + finalterm_) / 2.0;
}

bool Student_info_p::isPass() const
{
    return grade() >= 60;
}