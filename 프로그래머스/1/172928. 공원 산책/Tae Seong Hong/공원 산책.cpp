#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    unordered_map<char, int> direction = {{'E', 1}, {'W', -1}, {'S', 1}, {'N', -1}};
    
    for(int i=0;i<park.size();i++) {
        for(int j=0;j<park[i].size();j++) {
            if(park[i][j] == 'S') {
                answer.push_back(i);
                answer.push_back(j);
                break;
            }
        }
    }
    
    for(string route : routes) {
        
        /*
        current에서 다음 명령이 어딜 가르키는지
        answer[1] -> 동, 서
        answer[0] -> 남, 북
        direct -> 동 남 : 1 / 서 북 : -1
        move -> 이동할 거리
        
        index가 0이면, 증가 for문
        index가 1이면, 감소 for문
        
        먼저, move를 계산해서 방향에 맞춰서 맵 밖을 벗어나는지 확인
        그게 아니라면 start와 end를 줘서 경로 상에 뭐가 있는지 확인
        */
        
        int move = (route[2] - '0') * direction[route[0]]; // 이거 때문에 30분 헤맴
        int index = 0;
        int start = 0,
            end = 0;
       
        if(route[0] == 'N' || route[0] == 'S') {
            if(answer[index] + move < 0 || answer[index] + move > park.size() - 1)
                continue;
        } else {
            index = 1;
            if(answer[index] + move < 0 || answer[index] + move > park[0].length() - 1)
                continue;
        }
        
        if(move < 0) {
            start = answer[index] + move;
            end = answer[index];
        } else {
            start = answer[index];
            end = answer[index] + move;
        }
        
        bool isCan = true;
        if(route[0] == 'N' || route[0] == 'S') {
            for(int i=start;i<=end;i++) {
                if(park[i][answer[1]] == 'X') {
                    isCan = false;       
                    break;
                }
                    
            }
        } else {
            for(int i=start;i<=end;i++) 
                if(park[answer[0]][i] == 'X') {
                    isCan = false;
                    break;
                }
        }
        
        if(isCan)
            answer[index] += move;
    }    

    return answer;
}

/*
* 다음 명령 수행 조건
 이동하면 공원을 벗어나는지
 장애물을 만나는지

park = 공원 배열
routes = 수행 명령

* char는 int형으로 변환하면 ascii 코드로 나와서 실제 숫자를 받고 싶으면 '0'을 빼줘야 함
*/