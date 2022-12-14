//
// Created by aa on 22. 9. 15.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "Core.h"
#include "Grad.h"

using std::cin;
using std::vector;
using std::cout;
using std::endl;

bool compare_core_ptr(Core *p1, Core *p2)
{
    return p1->name() < p2->name();
}

int main()
{
    vector<Core*> pStudents;

    Core *pCore;
    char ch;
    while (cin >> ch){
        if (ch == 'U'){
            pCore = new Core;
        } else {
            pCore = new Grad;
        }
        pCore->read(cin);       // 포인터로 접근시에 Core 나 Grad 다 처리가 된다.
        pStudents.push_back(pCore);
    }

    std::sort(pStudents.begin(), pStudents.end(), compare_core_ptr);

//    for(auto i : pStudents){
//        cout << i->name() << " : " << i->grade() << endl;
//    }

    for (auto it= pStudents.begin(); it !=pStudents.end(); ++it){
        try {
            cout << (*it)->name() << " : " << (*it)->grade() << endl;
        } catch(std::domain_error &e){
            std::cerr << e.what() << endl;
            return 1;
        }
    }

    for (auto it= pStudents.begin(); it !=pStudents.end(); ++it){
        delete *it;
    }

    return 0;
}