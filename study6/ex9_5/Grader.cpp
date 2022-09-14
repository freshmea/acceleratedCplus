#include "Grader.h"
#include <algorithm>
#include <string>
#include <vector>

Grader::Grader(std::istream &in){
    Student_info_p student;
    while(student.read(in)){
        students_.push_back(student);
    }

    std::sort(students_.begin(), students_.end(), compare);
}

std::ostream &Grader::report(std::ostream &out) const
{
    std::string::size_type maxLen = 0 ;
    for (auto it = students_.cbegin(); it != students_.cend();++it){
        maxLen = std::max(maxLen, it->name().size());
    }

    for(auto it = students_.cbegin(); it != students_.cend(); ++it){
        out << it->name() << std::string(maxLen- it->name().size(), ' ') << " : " << ((it->isPass()) ? "Pass": "Fail") << std::endl;
    }
    return out;
}