#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_distance = 0;
    unordered_map<int, unordered_set<int>> node;
    
    for(int i=0;i<edge.size();i++) { // 양방향이니까 양쪽 노드에 각각 추가
        node[edge[i][0]].insert(edge[i][1]);
        node[edge[i][1]].insert(edge[i][0]);
    }
    
    vector<int> distance(n + 1, -1); // 노드가 숫자가 1부터라서 +1를 해야 0~7가 되어 1~6로 사용할 수 있음
    
    queue<int> q;
    
    // 시작 노드 1번, 거리는 0
    q.push(1);
    distance[1] = 0;
    
    while(!q.empty()) { // 큐가 빌때까지
        int current_node = q.front(); // 탐색해야할 노드를 가지고 옴
        q.pop(); // 꺼냈으니까 제거
        
        for(int next : node[current_node]) { // 탐색할 노드와 연결된 노드들을 추출
            if(distance[next] != -1) // 인접한 노드를 이미 방문했으면 pass
                continue;
            
            distance[next] = distance[current_node] + 1;
            if(max_distance < distance[next])
                max_distance = distance[next];
            q.push(next);
        }
    } 
    
    for(int i=1;i<distance.size();i++) {
        if(distance[i] == max_distance)
            answer++;
    }
    
    return answer;
}

/*
DFS/BFS 개념
 DFS 깊이 우선 탐색 : 시작 노드에서 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방식
 -> 최대한 한 방향으로 내려가고 내려갈 수 없으면 돌아와서 다른 길로 쭉 내려가는 방식
 -> 재귀 호출 또는 스택을 사용해서 구현함
 -> 모든 노드를 탐색해야 할 때
 
 BFS 너비 우선 탐색 : 시작 노드에서 인접한 노드를 먼저 탐색하는 방식
 -> 가까운 정점을 먼저 방문하고, 멀리 떨어져 있는 정점을 나중에 방문
 -> 큐를 사용해서 구현함
 -> 최단 거리를 구해야 할 때 / 가중치 없는 그래프
 
 DFS/BFS 모두 방문을 했는지 확인하는 과정이 필수로 들어가야 함 -> 이전 방법 작성해보면서 알게 되면서 복습된 내용
 
 큐로 어떻게 구현해야 할까
 시작 정점(1번 node)를 queue에 저장
 queue에서 1번 node를 꺼내서 1번 노드랑 가까운 걸 찾음
 1번이랑 연결된 2, 3번을 set에서 꺼내서 방문했는지 확인
 방문한 노드는 제외, 안했으면 현재 거리에서 +1
 그럼, 시작 정점의 거리는 0 연결된 2번 3번 노드는 거리가 1로 저장
 2번과 3번을 탐색해야 하니까 각각 큐에 저장
 2번 노드 탐색  -> 1, 3, 4, 5를 꺼내지만 1, 3은 이미 방문했음 pass -> 4, 5번 각각 처리
 반복하다 최종적으로 6번 노드까지 탐색하면 큐는 비게 됨 -> 계속 꺼내기 때문
 
 방문한 노드를 계산하는 방법 -> 미리 리스트를 만들어두고 거리를 -1로 설정한다.
 
 새 문법
 * queue -> <queue> 헤더 필요
  - 선언 queue<int> q
  - 삽입 q.push()
  - 확인 q.empty() -> 비었으면 true 아니면 false
  - 추출 q.front() -> 큐의 맨 앞 값을 꺼내옴
  - 제거 q.pop() -> 큐의 맨 앞 값을 제거
 
 * vector 선언 시 (size, default) 로 vector 초기화 가능함
*/


/*
그래프는 오랜만이라 풀 수 있을까잉
2학년 때 이후로 첨인데 ㅋㅋㅋㅋ
예전에는 n개의 노드만큼 동적 메모리로 지정하고, 어떻게해서 풀었던 거 같은데 흠냐흠냐

각 노드는 1~n
1번 노드에서 가장 먼 노드의 개수
최단 경로로 이동했을 때 간선의 개수가 가장 많은 노드

* 어떻게 풀어보지
 일단 최단 경로는 제외하고, 탐색을 하는걸 목표로 풀어보자
 완전 탐색을 한다. 5번 node를 찾을 때 2번 노드에 물어보고 3번 노드에 물어보는 식으로다가
 
 일단 find의 경우 iterator을 반환함
 if(it != map.end()) -> 키가 있는 경우 처리
 
 매개변수로 넘길 경우 그냥 넘기면 복사되서 오래걸리니까 const &로 참조하도록 함
 참조해서 사용하는 경우 node.at(1)으로 사용해야 오류가 안뜸 -> 참조하면 값 수정이 안되기 때문
 
 1번 node를 호출했을 때 안에 찾으려는 노드가 있는지 확인
 key로 저장? value에 저장? -> 있으면 2번 노드를 탐색해야 함
 내 생각에는 unordered_map<int, unordered_set<int>> node로 선언
 key 불려서 set안에 찾는 노드가 있는지 확인하는 과정을 거친다.
 
 int find_node(const unordered_map<int, unordered_set<int>>& node, int prev, int n, int search, int distance) {
    // 거리가 2이상인데 1번 노드를 안다면 그건 최단거리가 아님
    auto it = node.at(n).find(1);
    if(it != node.at(n).end() && distance >= 2) 
        return 0;
    
    // 단말 노드에서 되돌아와서 반복 하는걸 방지 -> set.size() 1이면 단말노드라고 판단
    if(node.at(n).size() == 1)
        return distance;
    
    /// 위 조건들은 pass하면, 해당 노드(n)에 찾는 노드(search)가 있는지 확인
    it = node.at(n).find(search);
    if(it == node.at(n).end()) { // 못 찾으면 인접 노드를 통해서 탐색
        for(int element : node.at(n)) {
            // if(element == 1) // 1번 노드는 pass
            //     continue;
            if(prev == element) // 이전 노드 pass
                continue;
            
            distance = find_node(node, n, element, search, distance+1);
            
            if(distance != 0) {
                distance--;
                break;
            }
                
        }
    }
    
    return distance + 1;
}    
    
    node[1] = {2, 3}; 있는거 확인했으니까 거리 1 반환
    만약 search 5
    unordered_set은 출력이 랜덤임
    만약 못 찾아서 for문 돌면
    find_node(node, element, search)
    element = 2
    2번 노드에는 해당 값이 있으니까 1를 리턴할거임
    element = 3
    3번 노드에선 해당 값이 없으니까 또 set를 for문으로 돌거임
    그럼 3번에서 2번이 있으니까 결국엔 찾지만 거리가 3이 됨
    즉 찾자마자 for문을 멈출 트리거가 필요함
    또한, 3번을 먼저 들어갔을 때 2번을 통해 탐색하지 않도록 하는 방법도 필요함
    -> 1번 노드가 있는지 확인 후 search를 찾음 -> 어차피 1번 노드부터 찾는거라서 1번 노드랑 인접한 노드들은 이 필터에 안 걸림
    -> find_node를 재귀호출 했을때만 2번노드를 탐색하면 걸리게 되어서 해결 가능할듯 -> 아니야 이건 틀린 방법이야 
*/