#include <string>
#include <vector>

using namespace std;

int find_answer(const vector<int>& numbers, int target, int index, int sum) {
    if(index == numbers.size()) {
        if(target == sum)
            return 1;
        else
            return 0;
    }
    
    return find_answer(numbers, target, index + 1, sum + numbers[index]) + find_answer(numbers, target, index + 1, sum - numbers[index]);
}
    
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = find_answer(numbers, target, 0, 0);
    return answer;
}

/*
1 1 1 1 1
+1+1+1+1+1
+1+1+1+1-1
+1+1+1-1-1
+1+1-1-1-1
+1-1-1-1-1
-1-1-1-1-1
-1-1-1-1+1
-1-1-1+1+1
-1-1+1+1+1
-1+1+1+1+1

+1-1+1+1+1
+1-1-1+1+1
+1-1-1-1+1

+1+1-1+1+1
+1+1-1-1+1

DFS = 재귀호출로 앞을 고정하고 뒤에를 2가지씩으로 분류하면?
모든 경우의 수를 탐색하고 답을 찾아야하니까 일단 DFS는 맞음

첫 수 1를 고정하고 find_answer로 재귀호출 실행 number의 끝에 다다를때까지로 해서
첫 수를 주고 + - 로 2가지 재귀호출 -> 끝까지 내려가서 target과 같으면 return 1 최종적으로 return +++

보통 재귀호출 할때를 생각해보자
calc(num - 2) + calc(num + 2)
이런 식으로 계산을 많이 했던 거 같음
index 0 : +1 -> index 1 : +1 index 2: +1 -1 index 2: + 1 -1 -1 이런식으로 각각 계산되도록
그러면 +1인 상태에서 
+1 -> {+1, -1} -> {}

calc(numbers[index+1] * 1)
calc(numbers[index+1] * -1)
그러면 return calc(numbers[index+1] * 1) + calc(numbers[index+1] * -1)

재귀호출 구현 시 주의해야 할 사항 합이 초기화되지 않도록 주의해야함
*/