#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int answer = 0, max = 1;
    int x, i;
    int total_signals_sec, start_yellow_sec, yellow_signal_sec;
    for(i=0;i<signals.size();i++) {
        total_signals_sec = signals[i][0] + signals[i][1] + signals[i][2];
        max = lcm(max, total_signals_sec);
    }
    
    for(x=0;x<max;x++) {
        for(i=0;i<signals.size();i++) {
            total_signals_sec = signals[i][0] + signals[i][1] + signals[i][2];
            start_yellow_sec = signals[i][0] + 1;
            yellow_signal_sec = x % total_signals_sec;
            
            if(yellow_signal_sec < start_yellow_sec || yellow_signal_sec > start_yellow_sec + signals[i][1] - 1)
                break;
         
        }
        if(i==signals.size()) {
            answer = x;
            break;
        } else {
            answer = -1;
        }
    }
    return answer;
}

/*
- signal 1
처음 시작 값 : 3초
노란불 : +5초
13 % 5 = 3

- signal 2
처음 값 : 6초
노란불 : +7초
13 % 7 = 6

서로 만나는 최대값 x
1~x 사이에 13 % 5 == 3 and 13 % 7 == 6 인 값을 찾는다

노란불이 지속된다면?
3~5초 시작 + 7초 -> x % 7 == 3 ~ 5
4초 시작 + 7초 -> x % 7 == 4
3초 시작 + 4초 -> x % 4 == 3

- 문제를 풀고 테스트 결과 보고 든 생각
아마 최대값에 대한 제한 -> 즉, 최소공배수를 설정 안해서 각종 테스트 결과에서 문제가 발생

- 확장 이전 문제 풀이 : limit를 주지 않고 x의 최대값을 임의로 2,000,000 으로 설정함
- 확장 이후 문제 풀이 방법
LCM(최소공배수) 구하는 방법은 GCD(최대공약수)를 구해야 함
int gcd(int a, int b) {
    while(b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
위 방식을 유클리드 호제법이라고 함
핵심은 두 수 a, b의 최대 공약수는 `b`와 `a를 b로 나눈 나머지`의 최대공약수와 같다
a는 처음 값에서 나누는 값으로 전환됨
b는 나누는 값에서 나머지로 전환됨
그렇게 가다가 나머지가 0이 되면 최대공약수가 정해짐

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
최소공배수는 서로수를 제외한 공통되는 수가 2번 들어가게 됨
따라서 공통되는 가장 큰 값 = 최대공약수를 한 번 나누어 최소공배수를 구함
*/