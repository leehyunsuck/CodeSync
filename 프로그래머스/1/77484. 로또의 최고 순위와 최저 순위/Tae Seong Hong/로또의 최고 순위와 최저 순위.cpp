#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> correct(46, 0);
    int max = 7,
        min = 7;
    
    for(int lotto : lottos) { // 민호가 썼으면 1
        correct[lotto] += 1;   
    }
    
    for(int win_num : win_nums) {
        if(correct[win_num] == 1) {
            max--;
            min--;
        }
    }
    
    max -= correct[0];
    
    if(max == 7)
        max--;
    
    if(min == 7)
        min--;
    
    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}

/*
lottos : 민우가 구매한 로또 번호
win_nums : 당첨 번호

0은 모든 가능/불가능
최고 순위와 최저 순위

6개 일치 : 1등
5개 일치 : 2등
4개 일치 : 3등
3개 일치 : 4등
2개 일치 : 5등
1개 일치 : 6등
*/