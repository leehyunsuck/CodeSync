#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

bool compare_word(string source, string target) {
    int count = 0;
    for(int i=0;i<source.length();i++) {
        if(source[i] != target[i])
            count++;
    }
    
    return count == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int index = 0;
    queue<string> change_word;
    unordered_map<string, int> visited; // 해당 단어를 방문했는지 확인
    
    change_word.push(begin);
    
    while(!change_word.empty()) {
        string current = change_word.front();
        change_word.pop();

        for(int i=0;i<words.size();i++) { // 모든 단어 집합을 순회
            if(visited[words[i]] != 0) // 방문했던거면 pass
                continue;
            
            if(compare_word(current, words[i])) { // 변경될 수 있는 단어만, 탐색 대상으로 추가
                if(words[i] == target) {
                    answer = visited[current] + 1;
                    break;
                }
                change_word.push(words[i]);
                visited[words[i]] = visited[current] + 1;
            }
        }
    }
    
    return answer;
}

/*
DFS 문제인거 확인 -> 가 아니라 최소 몇 단계니까 BFS인 듯

한 번에 한 개의 알파벳만 변경 가능
words에 있는 단어로만 변환 가능
hit -> cog
꺼낸 단어가 words에 있는 단어 중에 바꿀 수 있는게 있는지 있으면 해당 단어를 push
그 단어에서 또 바꾸고를 반복
target을 찾으면 그 값을 출력

문제를 이해 못하고, words에 단어를 왼쪽에서 오른쪽으로 돌았음
기존 코드 : for(int i=current.second + 1;i<words.size();i++) {
다시 읽어보니, 그런 말은 없었고, words 집합에서 다음으로 바뀔 수 있는 단어를 큐에 추가하는 식으로 변경

*/