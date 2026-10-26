#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    Rectangle(int w, int h);    // 생성자  
    ~Rectangle();               // 소멸자
    int calcArea();
};

Rectangle::Rectangle(int w, int h) {
    cout << "생성자 호출!" << endl;
    width = w;
    height = h;
}

Rectangle::~Rectangle() {
    cout << "소멸자 호출!" << endl;
}

int Rectangle::calcArea() {
    return width * height;
}

int main() {
    Rectangle r{ 3, 4 };

    cout << "사각형의 넓이 : " << r.calcArea() << endl;
    return 0;   // 프로그램 종료 시 소멸자 호출(~rectangle())
} 