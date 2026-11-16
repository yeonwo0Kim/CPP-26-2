#include "user.h"

// User 객체 생성하면 체력 20
User::User() {
    hp = 20;
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