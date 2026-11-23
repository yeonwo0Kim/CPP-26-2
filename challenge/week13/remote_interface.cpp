#include <iostream>

class RemoteControl {
    public:
        // 순수 가상 함수 정의
        virtual void TurnON() = 0;
        virtual void TurnOFF() = 0;
};

class Television : public RemoteControl {
public:
    void TurnON() {
        std::cout << "TV를 켭니다." << std::endl;
    }

    void TurnOFF() {
        std::cout << "TV를 끕니다." << std::endl;
    }
};

class Refrigerator : public RemoteControl {
public:
    void TurnON() {
        std::cout << "냉장고를 켭니다." << std::endl;
    }

    void TurnOFF() {
        std::cout << "냉장고를 끕니다." << std::endl;
    }
};

int main() {
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();
    remoteTV->TurnOFF();

    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();
    remoteRefrigerator->TurnOFF();

    delete remoteTV, remoteRefrigerator;
    return 0;
}