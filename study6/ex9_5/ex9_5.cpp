//
// Created by aa on 22. 9. 14.
//
#include "Grader.h"
#include <iostream>
using std::cin;
using std::cout;

int main()
{
    Grader grader(cin);
    grader.report(cout);
    return 0;
}