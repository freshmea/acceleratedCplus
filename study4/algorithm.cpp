#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool f(vector<int>::value_type value){
    return value == 6;
}

vector<int>::value_type square(vector<int>::value_type value){
    return value * value;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 6, 10};
    int nums2[10];

    copy(nums, nums+10, nums2);

    cout << "copy result nums2 : ";
    for(int i =0;i<5; ++i)
        cout << nums2[i] << " ";
    cout << endl;

    vector<int> vec;
    vec.reserve(100);
    cout << "vec.capacity() : ";
    cout << vec.capacity()<< endl;
    cout << "vec.size() : ";
    cout << vec.size() << endl;

    for(int i=0;i != 5; ++i){
        vec.push_back(nums[i]);
        vec.shrink_to_fit();
        cout << "vec.capacity() : ";
        cout << vec.capacity()<< endl;
        cout << "vec.size() : ";
        cout << vec.size() << endl;

    }


    vector<int> vec2(nums, nums+10);
    cout << "vec2 : ";
    for(auto const& i : vec2)
        cout << i << " ";
    cout << endl;

    cout << " vec2 : ";
    for(vector<int>::const_iterator it = vec2.cbegin();it!= vec2.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    int *p = find(nums, nums+10, 6);
    cout << "*p : " << *p << endl;

    vector<int>::const_iterator it = find(vec2.cbegin(), vec2.cend(), 6);
    // *it = 16; error 바꿀 수 없다.
    cout << "*it : " << *it << endl;

    vector<int>::const_iterator it2 = find_if(vec2.cbegin(), vec2.cend(), f);
    cout << "*it2 : " << *(it2+1) << endl;

    vector<int> vec3 = vec2;
//    vector<int>::iterator b = remove(vec3.begin(), vec3.end(), 6);
//    vec3.erase(b, vec3.end());
//    vec3.erase(remove(vec3.begin(), vec3.end(), 6), vec3.end());
    vec3.erase(remove_if(vec3.begin(), vec3.end(), f), vec3.end());

    cout << "vec3 remove 6 : ";
    for(auto i : vec3){
        cout << i << " ";
    }
    cout << endl;


    cout << "vec removecopy 6 : ";
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;
    cout << "vec2 removecopy 6 : ";
    for(auto i : vec2){
        cout << i << " ";
    }
    cout << endl;

    remove_copy(vec.cbegin(), vec.cend(), back_inserter(vec2), 3);

    cout << "vec removecopy 6 : ";
    for(auto i : vec){
        cout << i << " ";
    }
    cout << endl;
    cout << "vec2 removecopy 6 : ";
    for(auto i : vec2){
        cout << i << " ";
    }
    cout << endl;

    int sum = accumulate(vec2.cbegin(), vec2.cend(), 0);
    cout << "sum : " << sum << endl;

    transform(vec.cbegin(), vec.cend(), back_inserter(vec2), square);
    cout << "vec transform square  : ";
    for(auto i : vec2){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}