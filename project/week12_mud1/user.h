#include <iostream>
using namespace std;

class User {
private:
    int hp;

public:
    void IncreaseHP(int inc_hp);  // 체력 증가
    void DecreaseHP(int dec_hp);  // 체력 감소
    int GetHP();                  // 현재 체력 반환
    User();                       // 사용자 생성
};
