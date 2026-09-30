#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 100, b = 200;

    cout << "a = " << a << ", b = " << b << endl;

    swap(a, b);

    cout << "a = " << a << ", b = " << b << endl;
    return 0;
}