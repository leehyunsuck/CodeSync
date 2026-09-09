#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> open_word;
    int i;
    
    char last_str = words[0][words[0].size()-1];
    open_word[words[0]]++;
    
    for(i=1;i<words.size();i++) {
        open_word[words[i]]++;
        if(last_str == words[i][0] && open_word[words[i]] <= 1) {
            last_str = words[i][words[i].size()-1];
            continue;
        }
        
        break;
    }
    
    if(i==words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(i%n + 1);
        answer.push_back(i/n + 1);
    }

    return answer;
}

/*
왼쪽부터 순서대로 이어지게끔
무조건 앞 사람이 말한 단어의 뒷부분으로 시작해야 함
이전에 등장했던 단어는 사용 불가능함
한 글자인 단어는 인정 안함

* 풀이
 이전에 등장했던 단어 체크 -> map에 저장해두고 맵에서 꺼냈는데 1이면 썼던걸로 체크
 뒤에 문자를 다음 입력으로 사용해서 if문으로 비교하고 처리하게 하면 될듯
 
 몇번 사람 몇번째인지 구하기
 n = 3, 0 1 2 | 3 4 5 | 6 7 8
 n = 1, 0 3 6
 n = 2, 1 4 7
 n = 3, 2 5 8
 i = 0 3 6 % 3 -> 0이면 첫번째 사람
 i = 1 4 7 % 3 -> 1이면 두번째 사람
 i = 2 5 8 % 3 -> 2이면 세번째 사람
 즉, i % n은 몇번째 사람인지 구하기 가능
 
 
*/