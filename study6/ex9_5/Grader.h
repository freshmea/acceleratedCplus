//
// Created by aa on 22. 9. 14.
//

#ifndef ACCELERATEDCPLUS_GRADER_H
#define ACCELERATEDCPLUS_GRADER_H
#include <vector>
#include <iostream>
#include "student_info_p.h"

class Grader {
private:
    std::vector<Student_info_p> students_;
public:
    explicit Grader(std::istream& in);

    std::ostream& report(std::ostream& out) const;
};


#endif //ACCELERATEDCPLUS_GRADER_H
