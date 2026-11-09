#include <iostream>
using namespace std;
class Circle {
    private:
        int radius;
    public:
        Circle() { radius = 10; }
        ~Circle() { }
        void SetRadius(int radius) { this->radius = radius; }
        int GetRadius() const { return radius; }
};

int main() {

    Circle* p = new Circle();
    // const 객체를 가리키는 포인터 -> 고정된 객체를 가리키는 포인터
    const Circle *pConstObj = new Circle();
    Circle *const pConstPtr = new Circle();

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl<<endl;
    
    p->SetRadius(30);
    // pConstObj->SetRadius(30);
    // pConstObj는 const 객체를 가리키는 포인터이기 때문에 객체의 값을 변경할 수 없음
    pConstPtr->SetRadius(30);

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl;
    return 0;
}