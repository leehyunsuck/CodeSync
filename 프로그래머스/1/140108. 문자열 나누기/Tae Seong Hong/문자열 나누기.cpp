#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    vector <int> state(2, 0);
    
    for(char n : s) {
        if(x == '0')
            x = n;
        
        if(x == n)
            state[0] += 1;
        else
            state[1] += 1;
        
        if(state[0] == state[1]) {
            answer++;
            x = '0';
            state.assign(2, 0);
        }
    }
    
    if(state[0] != 0)
        answer++;
    
    return answer;
}

/*
s = 입력된 문자열
x = 시작 문자

x인 문자
x가 아닌 문자

1. 두 횟수가 같을 경우
  s에서 분리한 문자열을 빼고 반복
   -> 남은 부분이 없으면 종료
   
2. 두 횟수가 다른 상태인데 끝나면 읽은 문자열을 분리하고 종료

x = b -> 1
!x = a -> 1
  => result += 1

x = n -> 1
!x = a -> 1
  => result += 1

*/