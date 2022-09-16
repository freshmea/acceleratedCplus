//
// Created by aa on 22. 9. 15.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "Core.h"
#include "Grad.h"
#include "Handle.h"

using std::cin;
using std::vector;
using std::cout;
using std::endl;

bool compare_handle_ptr(const Handle<Core>& h1, const Handle<Core>& h2)
{
    return h1->name() < h2->name();
}

int main()
{

    vector<Handle<Core> > pStudents;

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

    std::sort(pStudents.begin(), pStudents.end(), compare_handle_ptr);

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

    return 0;
}