#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y;

    // 보드판 초기화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임 코드
    int k = 0;
    char currentUser = 'X';
    while(true) {
        // 1. 누구 차례인지 출력
        switch (k % 3) {
            case 0:
                cout << (k % 3) + 1 << "번 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << (k % 3) + 1 << "번 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
            case 2:
                cout << (k % 3) + 1 << "번 유저(△)의 차례입니다 -> ";
                currentUser = 'A';  // △를 A로 표시
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 모든 칸이 차면 종료
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] != ' ') {
                    checked++;
                }
            }
        }
        if (checked == numCell * numCell) {
            cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }

        // 7. 빙고 시 승자 출력 후 종료 (가로, 세로, 대각선)
        bool bingo = false;

        for (int i = 0; i < numCell; i++) {
            // 가로줄 빙고 확인
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                cout << "가로에 모두 돌이 놓였습니다!: ";
                bingo = true;
            }
            // 세로줄 빙고 확인
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                cout << "세로에 모두 돌이 놓였습니다!: ";
                bingo = true;
            }
        }
        // 대각선 빙고 확인
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
            bingo = true;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
            bingo = true;
        }

        if (bingo) {
            cout << (k % 3) + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다." << endl;
            break;
        }
        k++;
    }
    return 0;
}