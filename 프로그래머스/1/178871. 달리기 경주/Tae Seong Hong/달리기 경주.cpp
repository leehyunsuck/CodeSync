#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> player_index;
    
    for(int i=0;i<players.size();i++) {
        player_index[players[i]] = i;
    }
    
    for(string calling : callings) {
        int index = player_index[calling];
        string temp = players[index - 1];
        swap(players[index], players[index - 1]);
        
        player_index[calling]--;
        player_index[temp]++;
    }
    
    answer = players;
    return answer;
}

/*
players = 현재 등수 선수 이름
callings = 등수 변경

* find 함수는 iterator를 반환함 / algorithm 헤더 필요
  따라서, 숫자형 인덱스를 구하려면 players.begin()을 통해 첫번째 주소값을 빼서
  int형으로 구함
  
* 처음 문제 풀이
 저번처럼 find 함수를 사용했는데 아닐까 다를까 벡터를 다 순회해서 시간 초과가 뜸
 
* 다른 방법 모색
 unordered_map<key 자료형, value 자료형> 이름;
 내부적으로 해시를 사용해서 key가 저장된 위치를 빠르게 계산함
 unordered_map은 자료형으로 바로 인덱스를 가져올 수 있어서 O(1)이 걸림
 이전 문제도 이걸로 풀면 시간 매우 단축될 거 같은 느낌
*/