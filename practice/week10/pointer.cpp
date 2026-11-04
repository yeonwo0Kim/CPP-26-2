#include <iostream>
using namespace std;

int main()
{
 int number = 10;
 // 변수number의주소를계산하여p에저장한다.
 int *p = &number;
 // p가가리키는공간에저장된값을출력한다.
 cout << *p << endl;
 return 0;
}