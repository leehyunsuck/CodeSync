#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    queue<pair<int, int>> move;
    vector<pair<int, int>> dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    move.push(make_pair(0, 0));
    
    while(!move.empty()) {
        pair<int, int> current = move.front();
        move.pop();
        
        for(int i=0;i<4;i++) {
            // {1, 0} {0, 1} {-1, 0} {0, -1} 4방향 탐색
            int mx = current.first + dxy[i].first;
            int my = current.second + dxy[i].second;
            if(mx < 0 || my < 0 || mx > maps.size() - 1 || my > maps[0].size() - 1)
                continue;
            if(maps[mx][my] != 1) 
                continue;
            maps[mx][my] = maps[current.first][current.second] + 1;
            move.push(make_pair(mx, my));
        }
    }
    
    answer = maps[maps.size() - 1][maps[0].size() - 1];
    if(answer == 1)
        answer = -1;
    
    return answer;
}

/*
1 1 1 1 1
1 0 1 0 1
1 0 1 1 1
1 1 1 0 1
0 0 0 0 1

1 0 1 1 1
1 0 1 0 1
1 0 1 1 1
1 1 1 0 0
0 0 0 0 1

최단거리니까 BFS를 써야되는 건 알겠음
BFS는 queue에 먼저 탐색할 곳을 넣고, 빼서 또 이동할 수 있는 공간을 찾고를 반복
BFS는 어디로든 가서 목적지에 도달하는 놈이 결국엔 1빠니까 굳이 값을 덮어씌울 필요는 없음
어떻게든 가다보면 목적지에 도달할 수 있다
시작 칸도 밟음 처리해줘야 함
1이면 큐에 추가 / 0 이면 큐에 추가 x
map에 distance를 넣고 목적지 도달하게 되면 끝냄 -> 어차피 먼저 도착한 놈이 가장 빠른 놈이니까

행과 열의 위치를 헷갈렸음 map.size() -> 행, map[0].size() -> 열인데
이걸 반대로 설정해서 테스트에서 다 틀림

* pair<int, int> -> 좌표 방식의 문제를 풀 때 유용함
 // 데이터 넣기 (두 가지 방법)
 {1, 2}           // 중괄호 {} 사용 (C++11 이상 추천)
 make_pair(3, 4);  // make_pair 함수 사용

 // 데이터 꺼내기
 pair<int, int> current
 current.first, current.second
*/