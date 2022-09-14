//
// Created by aa on 22. 9. 14.
//

#ifndef ACCELERATEDCPLUS_MEDIAN_H
#define ACCELERATEDCPLUS_MEDIAN_H
#include <vector>
#include <algorithm>

template <typename T>
const T median(const std::vector<T>& vec)
{
    std::vector<T> vec2 = vec;
    std::sort(vec2.begin(), vec2.end());

    typename std::vector<T>::size_type mid = vec2.size()/2;

    T median = (vec2.size() % 2) ? vec2[mid] : (vec2[mid]+vec2[mid-1]) /2;
    return median;
}
#endif //ACCELERATEDCPLUS_MEDIAN_H
