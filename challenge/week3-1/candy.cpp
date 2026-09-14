#include <iostream>
#include <string>
using namespace std;

int main()
{
    int money, price;
    cout << "현재 가지고 있는 돈: ";
    cin >> money;
    cout << "캔디의 가격: ";
    cin >> price;

    int candy = money / price;
    cout << "최대로 살 수 있는 캔디 = " << candy << endl;

    int result = money - (candy * price);
    cout << "캔디 구입 후 남은 돈 = " << result << endl;
    return 0;
}