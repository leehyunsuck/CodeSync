#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int count = 0;

    int line = num / w;
    if(num > w * line) {
        line++;
    }
    
    while(num <= n) {
        int next = 2 * line * w + 1 - num;
        num = next;
        count++;
        line++;
    }
    
    answer = count;
    
    return answer;
}

/*
왼쪽에서 오른쪽으로 택배를 놓음
가로로 w개 놓으면 오른쪽 -> 왼쪽
다시 왼쪽 -> 오른쪽
그 다음 택배 찾을 때 그 위에 있는 걸 꺼내야 가능
n : 택배 상자의 개수
w : 가로 개수
num : 꺼내는 상자 번호
최종적으로는 꺼낸 상자 + 1

* 풀이 생각
 일단 스택형식으로 쌓아두고 꺼내야 된다는 건 알겠음
 vector는 push_back을 통해서 값을 차곡차곡 넣을 수 있고 pop_back도 가능함
 vector를 사용해보기롤 결정

 먼저, 택배를 쌓아두고 꺼내는 건 그 다음
 어떻게 쌓을 건지?
 w 개수만큼 vector를 만든다? -> 일단 하는 방법을 모름
 w 만큼 %로 위치를 계산한다? -> 잘 계산하면 가능할 거 같음
 n = 22, w = 6
 n % w =  1  2  3  4  5  6 -> 0이면 끝에 도달했다고 판단
 n % w = 12 11 10  9  8  7 -> line을 계산해서 오른쪽꺼라고 판단하기?
 n % w = 13 14 15 16 17 18
 n % w =  /  / 22 21 20 19
 마지막에 위에꺼만 보고 line이 홀수면 오른쪽부터로 해서 계산하면 해당 w 위치를 판단 가능하지 않을까?
 
* 풀면서 나온 결과들
 22 % 6 = 4
 15 % 6 = 3
 즉, line이 짝수일때면 3번째 위치
     line이 홀수일때면 오른쪽에서 4번째 위치
     line이 홀수일때면 7 - 4 = 3
 다른 경우를 봐보자
 21 % 6 = 3
 line이 홀수니까 7 - 3 = 4 -> 왼쪽에서 4번째로 답이 나옴
 그러면 (w + 1) - (num % w) 하면 될 듯?
 
 찾는 num의 가장 위에 값을 구해야 될 듯
 n-- 하면서 index 값이 나오는 위치를 찾음 -> n개니까 가장 마지막에 쌓인 박스부터 찾아옴
 일단 line이 홀수라면 index 구하는 형식으로 위치를 구함
 만약, 다음 line에 있는 경우가 있을수도 있음
 ex) 가장 위에 값이 14라면?
 19일때 line을 줄여야 함 -> 어떤 기준으로
 19라는 건 index가 6일 때 끝에 다다름
 line이 짝수면, 위치 계산을 n % w 로 원래대로 하면 됨
 단, n % w 하면 0인 경우가 있으면 이때만 +6을 한다?
 
 find_index == index면 그 값부터 line을 줄이면서 찾는다?
 조금 비효율적인거 같긴한데 일단 해보자
 
     // 박스 번호가 1부터니까 1부터 n까지 생성
    box.push_back(0); // push_back은 0부터 들어가서 그걸 방지하기 위함
    for(int i=1;i<=n;i++) {
        if(i % w == 0) {
            line++;
        }
        box.push_back(i);
    }
    
    int find_index = (w + 1) - (num % w);
*/

    /*
    아니 근데 이거 이렇게 풀 수 있는 거 아닌가?
    어떻게? w = 6 num = 2
    2잖아 일단 w % num = 2지?
    line = 2면
    그 다음 값은 (6 * 2) - ((w % num) - 1)
    12 - 1 = 11
    그럼 그 다음 왼쪽부터니까
    (6*2) + (w%2) -> 12 + 2 = 14
    
    다른 예를 들어서 풀어보자
    3이면 그 다음 값
    (6*2) - (w % num - 1) = 12 - 2 = 10
    그 다음 값
    (6*2) + (w % num) = 12 + 3 = 15
    
    일단 최대 line을 구하는 방법
    n = 22, w = 6
    22 / 6 = 3.????
    if(w * 3 < num) line + 1; -> 4
    
    n = 2, w =3
    line = 0 = n / w
    if(w * 0 < n) line + 1 -> 1
    
    num = 8 / line = 4
    8이 무슨 라인인지 계산할 수 있을까?
    8 / 6 -> 1.???
    반올림해서 2니까 line = 2
    위에 있는 값을 구하기
    line(2) % 2 == 0 -> (w * line) + (w % num - 1) -> (6 * 2) + (8 % 6 - 1) = 17
    line(3) % 2 == 1 -> (w * line++) - (w % num - 1) -> (6 * 4) - (6 % 17 - 2) 
    line(4) % 2 == 0 -> (w * line)  + (w % num - count) -> (6 * 4) + (6 % 20 - 3)
    
    * 이게 진짜 규칙 num = 2
    line(1) % 2 == 1 -> (w * line++) - (num % w - count) -> (6 * 2) - (2 % 6 - 1) -> 11
    line(2) % 2 == 0 -> (w * line) + (num % w) -> (6 * 2) + (2 % 6) -> 14
    line(3) % 2 == 1 -> (w * line++) - (num % w - 1) -> (6 * 4) - (2 % 6 - 1) -> 23
    line(4) % 2 == 0 -> (w * line) + (num % w) -> (6 * 4) + (2 % 6) -> 26
    
    num = 11일때는 안 맞음
    ---
    1 + 12 = 13
    2 + 11 = 13
    ... 13
    line = 1, w = 6
    6 그다음 칸 6 + 1 = 13
    (line * w) + (line * w) + 1 = 13
    2 * line * w + 1 = 13
    next + num = 13
    next + num = 2 * line * w + 1
    next = 2 * line * w + 1 - num
    찾았다 이거네

    */