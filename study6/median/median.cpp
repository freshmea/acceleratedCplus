//
// Created by aa on 22. 9. 14.
//
#include "median.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> nums = {100, 50, 30, 10, 30, 23, 32, 41, 51, 12};
    cout << "median : " << median(nums) << endl;
    return 0;
}