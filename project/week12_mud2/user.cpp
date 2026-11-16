#include "user.h"

// User 객체 생성하면 체력 20
User::User() {
    hp = 20;
    itemCnt = 0;
}

// 전달받은 값만큼 체력 증가
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

// 전달받은 값만큼 체력 감소
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

// 현재 체력
int User::GetHP() {
    return hp;
}

// 아이템 개수 증가
void User::IncreaseItemCnt() {
    itemCnt++;
}

// 출력 연산자 중복 정의(오버로딩)
ostream& operator<<(ostream& os, User& user) {
    os << "현재 HP는 " << user.hp << "이고, 먹은 아이템은 총 " << user.itemCnt << "개입니다.";
    
    return os;
}