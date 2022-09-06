#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    default_random_engine engine(rd());
    uniform_real_distribution<double> dis(0, 10);
    vector<double> numbers;

    int i;
    for(i=0;i<10;i++){
        numbers.push_back(dis(gen));
    }

    for(auto i : numbers)
        cout << i << "  ";
    cout << endl << "average : "<< accumulate(numbers.begin(), numbers.end(), 0.0)/(i+1);
}