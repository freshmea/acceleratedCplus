//
// Created by aa on 22. 9. 15.
//

#ifndef ACCELERATEDCPLUS_CORE_H
#define ACCELERATEDCPLUS_CORE_H
#include <string>
#include <vector>

std::istream& read_hw(std::istream& in, std::vector<double>& homeworks);

class Core{
public:
    Core();
    explicit Core(std::istream& in);

    std::istream& read(std::istream& in);

    std::string name() const{return name_;}
    double grade() const;
protected:
    double midterm, finalterm;
    std::vector<double> homeworks;
    std::istream& read_common(std::istream& in);
private:
    std::string name_;
};


#endif //ACCELERATEDCPLUS_CORE_H
