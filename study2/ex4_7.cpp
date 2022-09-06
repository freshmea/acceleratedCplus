#include <iostream>
#include <random>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0, 10);
    vector<double> numbers;
    double sum = 0;
    for(int i=0;i<100;i++){
        numbers.push_back(dis(gen));
    }
    for(auto i : numbers)
        cout << i << endl;
    double a=0;
    cout << "average : "<<accumulate(numbers.begin(), numbers.end(), a)/100;
}