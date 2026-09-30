#include <iostream>
using namespace std;

// 전역변수
int a = 100, b = 200;

void swap() {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {

    cout << "a = " << a << ", b = " << b << endl;

    swap();

    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}