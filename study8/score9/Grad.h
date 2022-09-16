//
// Created by aa on 22. 9. 15.
//

#ifndef ACCELERATEDCPLUS_GRAD_H
#define ACCELERATEDCPLUS_GRAD_H
#include "Core.h"

class Grad : public Core {
public:
    Grad();
    explicit Grad(std::istream& in);

    virtual std::istream& read(std::istream& in);
    virtual Grad* clone() const;
    virtual double grade() const;
private:
    double thesis;
};


#endif //ACCELERATEDCPLUS_GRAD_H
