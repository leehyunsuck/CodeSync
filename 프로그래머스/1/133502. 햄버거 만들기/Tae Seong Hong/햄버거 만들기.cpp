#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    for(int ingre : ingredient) {
        stack.push_back(ingre);
        if(ingre == 1 && stack.size() > 3) {
            if(stack[stack.size() - 1] == 1
               && stack[stack.size() - 2] == 3
               && stack[stack.size() - 3] == 2
               && stack[stack.size() - 4] == 1) {
                answer++;
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();
                stack.pop_back();                        
            }
        }
    }
    return answer;
}

/*
빵일때 앞선 재료를 탐색하는 방법으로 했음

방식은 비슷하지만 더 좋은 풀이는 stack에 pop을 하는 것이 아닌,
인덱스로 처리해서 배열 안에 값을 덮어씌우면 보다 빠른 연산 결과를 얻을 수 있음

*/
