#include "Grad.h"
#include <iostream>

Grad::Grad()
:thesis(0.0){}

Grad::Grad(std::istream& in)
{
    read(in );
}

std::istream& Grad::read(std::istream& in)
{
    read_common(in);
    in >> thesis;
    ::read_hw(in, homeworks );
}

double Grad::grade() const
{
    return std::min(Core::grade(), thesis);
}

Grad* Grad::clone() const
{
    return new Grad(*this);
}