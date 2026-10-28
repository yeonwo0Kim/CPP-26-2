#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int i = 0;
    int sum = 0;

    while(true) {
        int score;
        cout << "성적을 입력하시오 (종료는 -1): ";
        cin >> score;
        // -1 입력하면 종료
        if (score == -1)
            break;
        // 입력한 점수(score)를 scores에 push
        scores.push_back(score);
    }

    // 점수 합
    for(auto& value : scores) {
        sum += value;
    }
    
    double avg = (double) sum / scores.size();
    cout << "성적 평균: " << avg << endl;

    return 0;
}