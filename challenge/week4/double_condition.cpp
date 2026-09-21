#include <iostream>
using namespace std;

int main() {
    
    int n1, n2;

    cout << "두 양수를 입력하세요: " << endl;
    cin >> n1 >> n2;

    if (n1 > 0) {
        if (n2 > 0)
        {
            cout << n1 << ", " << n2 << " 두 숫자 모두 양수입니다.\n" << endl;
        }
        else {
            cout << n1 << " 만 양수입니다.\n" << endl;
        }
    }
    else {
        cout << n1 << " 는 0이거나 음수입니다.\n" << endl;
    }
    return 0;
    
}
