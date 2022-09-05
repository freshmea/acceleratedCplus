#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout <<"input your name : ";
    string name;
    cin >> name;

    const string greeting = "Hello, " + name + "!";

    const int pad = 1;
    const int rows = 2 * pad +3;
    const int cols = greeting.size() + 2 * pad + 2;

    for(int r =1 ; r <= rows; ++r){
        int c = 0;
        while (c != cols){
            if(r == rows/2+1 && c == pad+1){
                //
            } else {
                if(:::){
                    '*';
                }else {
                    ' '
                }
            }
        }
    }

    return 0;
}