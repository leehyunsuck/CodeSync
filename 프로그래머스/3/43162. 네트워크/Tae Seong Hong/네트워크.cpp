#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> computer;
    unordered_map<int, int> connect;
    
    // 이번엔 안 헷갈리게 변수로 설정
    int row = computers.size();

    for(int i=0;i<row;i++) {
        if(connect[i] == 0) {// 아직 탐색되지 않았으면
            answer++;
            computer.push(i);
            connect[i] = answer;
        
            while(!computer.empty()) {
                int current = computer.front();
                computer.pop();

                for(int r=0;r<row;r++) {
                    if(current == r) // 본인 자리는 제외
                        continue;

                    if(connect[r] != 0) // 이미 번호가 지정된거면 pass
                        continue;

                    if(computers[current][r] == 1) { // 연결되어 있는 경우
                        connect[r] = connect[current];
                        computer.push(r);
                    }
                }
            }
        }
    }

    return answer;
    
}

/*
  j
i 1 1 0
  1 1 0
  0 0 1
  
  1 1 0 0
  1 1 0 0
  0 0 1 1
  0 0 1 1
  
  1번 컴퓨터 2번 컴퓨터 push net 1
  2번 컴퓨터 탐색 -> [current][0] == 1 -> 어떻게든 pass
  [current][2] -> 1 push 2 / net 1

computers[0][1] == computers[1][0]

DFS로 어디까지 내려갈 수 있는가
아니면 BFS로 몇 개의 경로가 나오는 가?
BFS로 내려가면서 맵 key로 네트워크 ID, Value로 set 이용해서 걔가 있는지 없는지로? 
마지막에 map 크기 출력하면 네트워크 개수 나오지 않나 -> 괜찮아 보이는데? 이렇게 해보자

* 문제 1 : queue front 값이 어디에 속해있는지 어떻게 알거냐?
-> map 안에 set에 있는거라서 map을 다 탐색해버리면 n(1)이여도 좀 비효율적인듯
  해결방법 : 방문한 노드를 기록하는 map 또는 set을 하나 더 만들어서 따로 관리한다
  아니면, 컴퓨터 위치 자리에 네트워크 주소를 저장하고, 0이 아니면 continue로 처리
  
* 문제 2 : 앞에 컴퓨터랑 연결되어 있지 않은 컴퓨터는 탐색 대상에서 아예 벗어나버림
  -> 따라서, BFS가 아니고 DFS인거 같음
  해결방법 : 순간 DFS라고 생각했는데 방문하지 않은 컴퓨터를 체크해서 방문하지 않은 컴퓨터에서부터 BFS를 돌려서 연결된게 있는지 확인하는 방법으로 해결
  
* 문제를 풀고 난 뒤 찾아본 결과
 해당 문제의 경우 섬 탐색, 미로 탐색처럼 길을 찾는 경우에는 BFS, DFS 뭘 사용해도 상관 없다
 
 보통 방문의 경우 다음 형태로 많이 사용함 -> vector<bool> visited(n, false);
 거리를 측정하는 것이 아니고, 방문했는지 안했는지가 핵심이라서
 
 
 --- DFS를 사용했을 경우 ---
 void dfs(int current, vector<vector<int>>& computers, vector<bool>& visited) {
    visited[current] = true;

    for(int next = 0; next < computers.size(); next++) {
        if(current == next)
            continue;

        if(visited[next])
            continue;

        if(computers[current][next] == 1)
            dfs(next, computers, visited);
    }
}

    그리고 solution()에서는:
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            dfs(i, computers, visited);
        }
    }
   로 재귀호출을 이용해서 방문했는지 확인 -> 연결됐는지 확인 -> 연결됐으면 해당 컴퓨터로 탐색을 반복하게 작성하면 됨
   
----- 개념 정리 한 번 더 -----
BFS의 경우 - 최단거리, 최소 이동 횟수, 몇 번 만에, 가장 가까운, n초 후
예: 미로 최단거리, 가장 먼 노드, 최소 버튼 횟수, 바이러스가 몇 초 후 퍼지는가

DFS의 경우 - 모든 경우 탐색, 끝까지 내려가면서 탐색, 경로 확인, 백트래킹
예: 타겟 넘버, 순열/조합 탐색, 모든 가능한 경로, 백트래킹

둘 다 가능한 경우 - 연결되어 있는가?, 몇 개의 그룹인가?, 영역이 몇 개인가?
예: 네트워크, 섬의 개수, 단지번호붙이기, 연결 요소, 바이러스 감염 가능한 컴퓨터 수
*/