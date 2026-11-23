#include <iostream>
using namespace std;

// 인터페이스로 변경
class User {
public:
    virtual void IncreaseHP(int inc_hp) = 0;  
    virtual void DecreaseHP(int dec_hp) = 0;  
    virtual int GetHP() = 0; 
    virtual ~User() = default;
    virtual void IncreaseItemCnt() = 0;
    virtual int GetItemCnt() = 0;
    virtual void doAttack() = 0;    // 순수 가상 함수

};

// User 상속
class Magician : public User {
private:
    int hp;
    int itemCnt;    // 아이템 먹은 횟수

public:
    Magician();
    void IncreaseHP(int inc_hp) override;  
    void DecreaseHP(int dec_hp) override;  
    int GetHP() override; 
    void IncreaseItemCnt() override;
    int GetItemCnt() override;
    void doAttack() override;
};

// User 상속
class Warrior : public User {
private:
    int hp;
    int itemCnt;    // 아이템 먹은 횟수

public:
    Warrior();
    void IncreaseHP(int inc_hp) override;  
    void DecreaseHP(int dec_hp) override;  
    int GetHP() override; 
    void IncreaseItemCnt() override;
    int GetItemCnt() override;
    void doAttack() override;
};

ostream& operator<<(ostream& os, User& user);