#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {50, 50, 0, 0};
    int index = 0;
    
    for(string line : wallpaper) {
        int col = -1;
        for(char file : line) {
            col++;
            if(file != '#')
                continue;
            
            answer[0] = min(answer[0], index);
            answer[1] = min(answer[1], col);
            answer[2] = max(answer[2], index + 1);
            answer[3] = max(answer[3], col + 1);        
        }
        index++;
    }
    
    return answer;
}

/*
wallpaper = 바탕화면의 상태
시작 격자점 lux, luy / 끝 점 rdx, rdy

0 1 2
1 . .
2 # .

lux가 이전 저장된 lux보다 작은 경우에만 변경
luy가 이전 저장된 luy보다 작은 경우에만 변경 -> 거의 건드릴 이유가 없음

rdx는 이전 저장된 rdx보다 큰 경우에만 변경
rdy는 이전 저장된 luy보다 큰 경우에만 변경
*/