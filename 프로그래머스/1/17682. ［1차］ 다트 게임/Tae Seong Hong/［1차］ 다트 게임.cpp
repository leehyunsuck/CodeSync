#include <string>
#include <iostream>
#include <vector>

using namespace std;

int sqrt(int score, int pow) {
    int result = 1;
    for(int i=0;i<pow;i++) {
        result *= score;
    }
    return result;
}

int solution(string dartResult) {
    int answer = 0;
    string score = "";
    vector<int> state(3, 0); // 0 1 2
    int index = 0;
    
    for(int i=0;i<dartResult.length();i++) {
        if(dartResult[i] - '0' < 0 || dartResult[i] - '0' > 10) { // 보너스와 옵션
            if(dartResult[i] == 'S')
                state[index] = sqrt(stoi(score), 1);
            else if(dartResult[i] == 'D')
                state[index] = sqrt(stoi(score), 2);
            else if(dartResult[i] == 'T')
                state[index] = sqrt(stoi(score), 3); 
            else if(dartResult[i] == '*') {
                if(index - 2  < 0)
                    state[index - 1] *= 2;
                else {
                    state[index - 2] *= 2;
                    state[index - 1] *= 2;   
                }
                continue;
            } else {
                state[index - 1] *= -1;
                continue;
            }
            
            index++;
            score = "";
        } else // 점수인 경우
            score += dartResult[i];
    }

    answer = state[0] + state[1] + state[2];
    
    return answer;
}

/*
다트 게임은 3번
각 기회마다 0~10점 획득 가능
S 1제곱, D 2제곱, T 3제곱
* 스타상 = 해당 점수와 바로 전에 얻은 점수를 각 2배
  스타상이 먼저 걸리면 해당 스타 점수만 2배
  스타 + 스타되면 중첩된 스타상 점수는 4배가 됨
  스타상 걸렸을 때 아차상이 있으면 효과가 중첩되서 -2배가 됨
  
# 아차상 = 해당 점수를 마이너스

입력 : 점수|보너스|[옵션]
1S 2D* 3T

대충 다음 숫자가 나오면 다음 세트
배열로 나눠서 * 이 나오면 이전 인덱스에 값을 추가해주는 식으로

*/