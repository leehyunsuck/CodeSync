#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<char> char_level = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    unordered_map<char, int> score_map;
    
    for(int i=0;i<survey.size();i++) {
        if(choices[i] < 4)
            score_map[survey[i][0]] += 4 - choices[i];
        else if(choices[i] > 4)
            score_map[survey[i][1]] += choices[i] - 4;
    }
    
    for(int i=0;i<char_level.size();i+=2) {
        if(score_map[char_level[i]] > score_map[char_level[i + 1]])
            answer += char_level[i];
        else if(score_map[char_level[i]] < score_map[char_level[i + 1]])
            answer += char_level[i + 1];
        else
            answer += char_level[i];
    }
    
    return answer;
}

/*
매우 동의 / 비동의 -> 3점
동의 / 비동의 -> 2점
약간 동의 / 비동의 -> 1점
모르겠음 -> 0점

점수가 같으면 두 유형 중 사전 순으로 빠른 유형

survey = 질문 지표
choices = 사용자 선택
return = 결과를 지표 번호대로

왜 TCMA인지 이해가 안갔는데, 위에 보니까 지표 순서가 정해져있었네
1번 R T 
2번 C F
3번 J M
4번 A N

* 틀렸던 부분
 for(int i=0;i<char_level.size();i+2) -> 무한 루프되어버려서 실행 초과
 증감식은 i가 증가한 값을 저장해야 되는데 잘못함 i+=2로 수정
 
 동일한 값에 대해서 덧셈을 처리 안했음
 if(choices[i] < 4)
    score_map[survey[i][0]] = choices[i];
else if(choices[i] > 4)
    score_map[survey[i][1]] = choices[i] - 4;

 score_map에 새로운 값으로 덮어씌우고 있었음

 제출 후 채점하기에서 실패 오지게 뜨길래 뭐가 문제인지 고민
 생각해보니까 매우 비동의가 3점인데 나는 그냥 순서대로 1 2 3점으로 점수를 주고 있었음
 1 -> 3 / 2 -> 2 / 3 -> 1
 3가지 모두 더하면 4가 나옴
 4 - 1 = 3, 4 - 2 = 2, 4 - 3 = 1
*/