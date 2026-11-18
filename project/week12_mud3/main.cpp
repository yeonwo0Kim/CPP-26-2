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
bool checkUser(User user);


int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    // 맵 배열 -> 벡터 변환
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
    
    // 두 명의 사용자 객체 생성
    Magician magician;
    Warrior warrior;

    // 두 명의 사용자 위치 저장할 변수
    int magician_x = 0;
    int magician_y = 0;

    int warrior_x = 0;
    int warrior_y = 0;

    // 차례 정보
    int turn = 0;

    // 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		bool moved = false; // 유저가 이동했는지 여부


         // 사용자의 입력을 저장할 변수
         string user_input = "";
         string userName = "";

         // 현재 턴 이름 확인
         if (turn % 2 == 0)
         {
             userName = "Magician";
         }
         else
         {
             userName = "Warrior";
         }

         cout << endl;
         cout << userName << endl;

         // 현재 체력 출력
         if (turn % 2 == 0) {
            cout << "현재 HP: " << magician.GetHP() << endl;
        }
        else {
            cout << "현재 HP: " << warrior.GetHP() << endl;
        }

         cout << "명령어를 입력하세요 (상,하,좌,우,지도,공격,정보,종료): ";
         cin >> user_input;

         if (user_input == "상")
         {
            if (turn % 2 == 0) {
                magician_y -= 1;

                bool inMap = checkXY(magician_x, mapX, magician_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    magician_y += 1;
                }
                else {
                    cout << "위로 한 칸 올라갑니다." << endl;
                    displayMap(map, magician_x, magician_y);
                    moved = true;
                }
            }
            else {
                warrior_y -= 1;

                bool inMap = checkXY(warrior_x, mapX, warrior_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    warrior_y += 1;
                }
                else {
                    cout << "위로 한 칸 올라갑니다." << endl;
                    displayMap(map, warrior_x, warrior_y);
                    moved = true;
                }
            }
        }

		else if (user_input == "하") {

            if (turn % 2 == 0) {
                magician_y += 1;

                bool inMap = checkXY(magician_x, mapX, magician_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    magician_y -= 1;
                }
                else {
                    cout << "아래로 한 칸 내려갑니다." << endl;
                    displayMap(map, magician_x, magician_y);
                    moved = true;
                }
            }
            else {
                warrior_y += 1;

                bool inMap = checkXY(warrior_x, mapX, warrior_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    warrior_y -= 1;
                }
                else {
                    cout << "아래로 한 칸 내려갑니다." << endl;
                    displayMap(map, warrior_x, warrior_y);
                    moved = true;
                }
            }
        }

         else if (user_input == "좌") {

            if (turn % 2 == 0) {
                magician_x -= 1;

                bool inMap = checkXY(magician_x, mapX, magician_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    magician_x += 1;
                }
                else {
                    cout << "왼쪽으로 이동합니다." << endl;
                    displayMap(map, magician_x, magician_y);
                    moved = true;
                }
            }
            else {
                warrior_x -= 1;

                bool inMap = checkXY(warrior_x, mapX, warrior_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    warrior_x += 1;
                }
                else {
                    cout << "왼쪽으로 이동합니다." << endl;
                    displayMap(map, warrior_x, warrior_y);
                    moved = true;
                }
            }
        }

		else if (user_input == "우") {

            if (turn % 2 == 0) {
                magician_x += 1;

                bool inMap = checkXY(magician_x, mapX, magician_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    magician_x -= 1;
                }
                else {
                    cout << "오른쪽으로 이동합니다." << endl;
                    displayMap(map, magician_x, magician_y);
                    moved = true;
                }
            }
            else {
                warrior_x += 1;

                bool inMap = checkXY(warrior_x, mapX, warrior_y, mapY);

                if (inMap == false) {
                    cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                    warrior_x -= 1;
                }
                else {
                    cout << "오른쪽으로 이동합니다." << endl;
                    displayMap(map, warrior_x, warrior_y);
                    moved = true;
                }
            }
        }

		else if (user_input == "지도") {

            if (turn % 2 == 0) {
                displayMap(map, magician_x, magician_y);
            }
            else {
                displayMap(map, warrior_x, warrior_y);
            }
        }

        else if (user_input == "정보") {

            if (turn % 2 == 0) {
                cout << magician << endl;
            }
            else {
                cout << warrior << endl;
            }
        }

        // 공격
        else if (user_input == "공격") {

            if (turn % 2 == 0) {
                magician.doAttack();
            }
            else {
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
			if (turn % 2 == 0) {
                magician.DecreaseHP(1);

                checkState(map, magician_x, magician_y, magician);

                if (!checkUser(magician)) {
                    cout << "Magician의 HP가 0 이하가 되었습니다." << endl;
                    cout << "게임을 종료합니다." << endl;
                    break;
                }
            }
            else {
                warrior.DecreaseHP(1);

                checkState(map, warrior_x, warrior_y, warrior);

                if (!checkUser(warrior)) {
                    cout << "Warrior의 HP가 0 이하가 되었습니다." << endl;
                    cout << "게임을 종료합니다." << endl;
                    break;
                }
            }
		}

		// 목적지에 도달했는지 체크
        bool finish = false;

        if (turn % 2 == 0) {
            finish = checkGoal(map, magician_x, magician_y);
        }
        else {
            finish = checkGoal(map, warrior_x, warrior_y);
        }

		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        // 다음 턴
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
bool checkUser(User user) {
    if (user.GetHP() <= 0) {
        return false;
    } else {
        return true;
    }
}
