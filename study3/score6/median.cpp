#include <stdexcept>
#include <algorithm>
#include <vector>
#include "median.h"
using std::domain_error;

double median(const std::list<double>& l) {
    std::vector<double> v(l.cbegin(), l.cend());
    if(v.empty()){
        throw domain_error("vector is empty");
    }
    std::vector<double> vec = v;
    sort(vec.begin(), vec.end());
    auto n = vec.size() / 2; // vector<double>::size_type
    return (vec.size() % 2) ? vec[n] : (vec[n] + vec[n - 1]) / 2;
}