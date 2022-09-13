#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include <string>
#include <vector>
class Student_info{
private:
    std::string _name;
    double _grade;
    double _midterm;
    double _finalterm;
    std::vector<double> _homeworks;
    char _fgrade;
    char _finalGrade;
public:
    Student_info(): _midterm(0), _finalterm(0), _fgrade('F'), _grade(0){}
    Student_info(std::istream&is){read(is);}
    bool operator<(const Student_info& rhs) const;
    std::istream& read(std::istream& in);
    char fgrade() {return _fgrade;}
    std::string name() const{return _name;}
    double grade() const{return _grade;}
    bool valid() const {return !_homeworks.empty();}
    char finalGrade(){return _finalGrade;}
};


#endif
