//
// Created by aa on 22. 9. 15.
//
#include <iostream>
#include <vector>
#include "Core.h"
#include "median.h"

double grade(double midterm, double finalterm, double median){
    return  0.211111 * midterm +0.4* finalterm + 0.4 * median;
}

double grade(double midterm, double finalterm, const std::vector<double>& hws) {
    if(hws.empty()){
        throw std::domain_error("homework vector is empty");
    }
    double homework = ::median(hws);
    return ::grade(midterm, finalterm, homework);
}

std::istream& read_hw(std::istream& in, std::vector<double>& homeworks)
{
    if(in) {
        homeworks.clear();
        double homework;
        while (in >> homework) {
            homeworks.push_back(homework);
        }
        in.clear();
    }
    return in;
}

Core::Core()
: midterm(0.0), finalterm(0.0)
{

}

Core::Core(std::istream& in)
{
    read( in);
}

std::istream& Core::read(std::istream& in)
{
    read_common(in);
    ::read_hw(in, homeworks);
    return in;
}

Core* Core::clone() const{
    return new Core(*this);
}
double Core::grade() const
{
    return ::grade(midterm, finalterm, homeworks);
}

std::istream& Core::read_common(std::istream& in )
{
    in >> name_;
    if (in ){
        in >> midterm >> finalterm;
    }
    return in;
}