#include <iostream>
using namespace std;

// 3. 입력받은 좌표의 유효성 체크
bool checkPosition(char board[3][3], int x, int y) {
    if (x >= 3 || y >= 3) {
        cout << x << ", " << y << ": ";
        cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    if (board[x][y] != ' ') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

// 5. 현재 보드판 출력
void printBoard(char board[3][3], int numCell) {
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
}

// 6. 모든 칸이 차면 종료
bool checkFull(char board[3][3], int numCell) {
    int checked = 0;
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != ' ') {
                checked++;
            }
        }
    }
    return checked == numCell * numCell;
}

// 7. 빙고 시 승자 출력 후 종료 (가로, 세로, 대각선)
bool checkBingo(char board[3][3], int numCell, char currentUser) {
    // 가로줄 빙고 확인
    for (int i = 0; i < numCell; i++) {
        if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
            return true;
        }
    }
    // 세로줄 빙고 확인
    for (int i = 0; i < numCell; i++) {
        if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
            return true;
        }
    }
    // 대각선 빙고 확인
    if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
        return true;
    }
    if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
        return true;
    }
    return false;
}

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
        switch (k % 2) {
            case 0:
                cout << (k % 2) + 1 << "번 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << (k % 2) + 1 << "번 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (!checkPosition(board, x, y)) {
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드판 출력
        printBoard(board, numCell);

        // 6. 모든 칸이 차면 종료
        if (checkFull(board, numCell)) {
            cout << "모든 칸이 다 찼습니다. 종료합니다." << endl;
            break;
        }

        // 7. 빙고 시 승자 출력 후 종료 (가로, 세로, 대각선)
        if (checkBingo(board, numCell, currentUser)) {
            cout << (k % 2) + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다." << endl;
            break;
        }
        k++;
    }
    return 0;
}