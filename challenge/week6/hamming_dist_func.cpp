#include <iostream>
#include <string>
using namespace std;

// 대문자 -> 소문자
string toLowerStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
    return str;
}

// 소문자 -> 대문자
string toUpperStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    return str;
}

// 대소문자 관계 없이 해밍거리 구하는 함수
int calcHammingDist(string s1, string s2) {
    int count = 0;

    // 대소문자 구분하지 않도록 소문자로 변환
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    if (s1.length() != s2.length()) {
        cout << "오류: 길이가 다름" << endl;
        return -1;
    } else {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    string s1, s2;

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    int count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;
    
    return 0;
}