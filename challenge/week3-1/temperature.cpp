#include <iostream>
#include <string>
using namespace std;

int main()
{
    float f;
    cout << "화씨온도: ";
    cin >> f;

    float c = (5.0 / 9.0) * (f - 32);
    cout << "섭씨온도 = " << c << endl;
    return 0;
}