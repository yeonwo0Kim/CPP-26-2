#include <stdio.h>

int main() {
    int n1, n2;

    printf("두 양수를 입력하세요: ");
    scanf_s("%d %d", &n1, &n2);

    if (n1 > 0) {
        if (n2 > 0)
        {
            printf("%d, %d 두 숫자 모두 양수입니다.\n", n1, n2);
        }
        else {
            printf("%d 만 양수입니다.\n", n1);
        }
    }
    else {
        printf("%d 는 0이거나 음수입니다.\n", n1);
    }
    return 0;
    
}