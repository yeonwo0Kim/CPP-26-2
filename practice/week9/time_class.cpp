#include <iostream>
using namespace std;

class Time {
public:
    int hour;       // 시 (0~23)
    int minute;     // 분 (0~59)

    Time(){}        // 오버로딩

    Time(int h, int m) {
        hour = h;
        minute = m;
    }

    void Print() {
        cout << hour << ":" << minute << endl;
    }
};

int main() {
    Time a;                 // 오버로딩으로 해결
    Time b (10, 25);        // 예전 방법
    Time c { 10, 25 };      // 최신 방법
    Time d = { 10, 25 };    // 간결하지않음

    a.Print();
    b.Print();
    c.Print();
    d.Print();

    return 0;
}