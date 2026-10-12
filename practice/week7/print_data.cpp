#include <iostream>
#include <string>
using namespace std;

class PrintData {
public:
    // 정수형, 실수형, 문자열형 데이터를 출력하는 멤버 함수 선언
    void print(int i) {
        cout << i << endl;
    }

    void print(double f) {
        cout << f << endl;
    }

    void print(string s = "No Data!") {
        cout << s << endl;
    }
};

int main() {
    PrintData obj;

    obj.print(1);
    obj.print(3.14);
    obj.print("C++14 is cool.");
    obj.print(); // 기본 매개변수 사용
    return 0;
}