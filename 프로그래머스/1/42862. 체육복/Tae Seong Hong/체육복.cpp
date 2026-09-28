#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> state(n + 2, 0);

    for(int l : lost) {
        state[l] -= 1;
    }
    
    for(int re : reserve) {
        state[re] += 1;
    }
    
    for(int i=1;i<state.size() - 1;i++) {
        if(state[i] > -1)
            answer++;  
        else if(state[i] == -1) {
            if(state[i - 1] == 1) {
                answer++;
                state[i] = 0;
                state[i - 1] = 0;
            } else if(state[i + 1] == 1) {
                answer++;
                state[i] = 0;
                state[i + 1] = 0;
            }
        }
    }
    
    return answer;
}

/*
n = 전체 학생 수
lost = 잃어버린 사람
reserve = 여벌을 갖고 있는 사람
return = 체육복을 가질 수 있는 최대 학생

여벌이 있어도 본인이 잃어버릴 수도 있음
*/