#include <iostream>
using namespace std;

class User {
private:
    int hp;
    int itemCnt;    // 아이템 먹은 횟수

public:
    virtual void IncreaseHP(int inc_hp) = 0;  
    virtual void DecreaseHP(int dec_hp) = 0;  
    virtual int GetHP() = 0; 
    User();  
    virtual ~User() = default;

    // 아이템 개수 증가
    virtual void IncreaseItemCnt() = 0;
    virtual int GetItemCnt() = 0;

    // 순수 가상 함수
    virtual void doAttack() = 0;

    // 출력 연산자 중복 정의(오버로딩)
    // friend -> private 접근
    friend ostream& operator<<(ostream& os, User& user);
};

// User 상속
class Magician : public User {

public:
    void doAttack();
};

// User 상속
class Warrior : public User {
public:
    void doAttack();
};
