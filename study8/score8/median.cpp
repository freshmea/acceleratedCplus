#include <stdexcept>
#include <algorithm>
#include <vector>
#include "median.h"
using std::domain_error;

double median(const std::vector<double>& v) {
    std::vector<double> v2(v.cbegin(), v.cend());
    if(v2.empty()){
        throw domain_error("vector is empty");
    }
    std::vector<double> vec = v2;
    sort(vec.begin(), vec.end());
    auto n = vec.size() / 2; // vector<double>::size_type
    return (vec.size() % 2) ? vec[n] : (vec[n] + vec[n - 1]) / 2;
}