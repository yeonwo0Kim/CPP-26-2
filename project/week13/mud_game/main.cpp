#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "user.h"

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user);
bool checkUser(User& user);


int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    // 맵 배열 -> 벡터 변환
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

    // 두 유저 객체 생성
    Magician magician;
    Warrior warrior;

    // 유저별 위치
    int magician_x = 0;
    int magician_y = 0;

    int warrior_x = 0;
    int warrior_y = 0;

    // 차례 관리
    int turn = 0;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		bool moved = false; // 유저가 이동했는지 여부

		// 사용자의 입력을 저장할 변수
		string user_input = "";

        // 현재 차례의 유저
        User* user;

        int user_x;
        int user_y;

        if (turn % 2 == 0) {
            user = &magician;
            user_x = magician_x;
            user_y = magician_y;

            cout << endl;
            cout << "= Magician 차례 =" << endl;
        }
        else {
            user = &warrior;
            user_x = warrior_x;
            user_y = warrior_y;

            cout << endl;
            cout << "= Warrior 차례 =" << endl;
        }

		// 현재 체력 출력
        // user는 포인터 변수이기 때문에 ->로 접근
		cout << "현재 HP: " << user->GetHP() << "  ";

		cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,공격,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				moved = true;
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				moved = true;
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				moved = true;
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				moved = true;
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
        else if (user_input == "정보") {
            // 현재 사용자 정보 보여주기
            cout << *user << endl;
        }
        else if (user_input == "공격") {
            if (turn % 2 == 0) {
                magician.doAttack();
            } else {
                warrior.doAttack();
            }
        }
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		if (moved == true) {
			user->DecreaseHP(1); // 이동 시 체력 소모
    
			checkState(map, user_x, user_y, *user);

            // magician, warrior 객체가 user 변수에 복사됨
            // 이동하면 변경된 위치를 실제 객체의 위치에 저장
            if (turn % 2 == 0) {
                magician_x = user_x;
                magician_y = user_y;
            }
            else {
                warrior_x = user_x;
                warrior_y = user_y;
            }

            // 이동했을 때만 체력 체크
			if (!checkUser(*user)) {
				cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

        // 다음 차례로
        turn++;

	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>>& map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 무기/갑옷, 포션, 적을 만났을 때 그에 대한 메시지 출력
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user) {
	// 적을 만나면 체력 2 감소
	if (map[user_y][user_x] == 2) {
		user.DecreaseHP(2);
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
	}
	// 포션을 만나면 체력 2 증가
	else if (map[user_y][user_x] == 3) {
		user.IncreaseHP(2);
		cout << "포션이 있습니다. HP가 2 증가합니다." << endl;
	}
    // 아이템을 만나면 아이템 개수 1 증가
    else if (map[user_y][user_x] == 1) {
        user.IncreaseItemCnt();
        cout << "아이템이 있습니다." << endl;
    }
}

// User 객체 넣으면 hp가 0인지 체크하고,
// 0이라면 false, 그렇지 않다면 true 반환
bool checkUser(User& user) {
    if (user.GetHP() <= 0) {
        return false;
    } else {
        return true;
    }
}
