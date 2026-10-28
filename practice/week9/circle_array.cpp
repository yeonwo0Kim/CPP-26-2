#include <iostream>
using namespace std;

class Circle {
    public:
        int x, y;
        int radius;
        Circle() {
            x = 0;
            y = 0;
            radius = 0;
        }
        Circle(int x, int y, int r) {
            this->x = x;
            this->y = y;
            this->radius = r;
            // 같은 변수 이름일 때 객체 내 속성과 매개변수 구분 위해
        }
        void Print() {
            cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl;
        }
};

int main(void) {
    Circle objArray[10];

    // 참조자 & 붙이지 않으면 배열의 객체가 복사되어 복사본만 수정되고 원본 객체는 기본 생성자의 초기값 0으로 유지
    // 배열 안에 있는 원본 객체를 직접 수정하기 위해 참조자 & 사용
    for (Circle& c: objArray) {
        c.x = rand()%500;
        c.y = rand()%300;
        c.radius = rand()%100;
    }
    for (Circle c: objArray)
        c.Print();
    
        return 0;
}