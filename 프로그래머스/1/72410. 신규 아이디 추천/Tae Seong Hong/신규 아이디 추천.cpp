#include <string>
#include <vector>
#include <iostream>
#include <regex>

using namespace std;

string preprocessor(string new_id) {
    // 1단계 : 대문자 -> 소문자로 변환
    for(int i=0;i<new_id.length();i++) {
        if((int)new_id[i] <= 90 && (int)new_id[i] >= 65)
            new_id[i] = (char)((int)new_id[i] + 32);
    }
    
    // 2단계 : 규칙 문자가 아닌 문자 제외
    regex rule_word(R"([^a-z0-9._-])");
    new_id = regex_replace(new_id, rule_word, "");

    // 3단계 : 마침표가 2번 이상이면 하나로 치환
    regex cont_dot(R"(\.{2,})");
    new_id = regex_replace(new_id, cont_dot, ".");
        
    // 4단계 : 마침표가 처음이나 끝이면 제거
    regex del_dot(R"(^\.|\.$)");
    new_id = regex_replace(new_id, del_dot, "");
    
    // 5단계 : 빈 문자열이면 a 대입
    if(new_id == "")
        new_id = "a";
    
    // 6단계 : 16자 이상이면
    if(new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
        regex check_dot(R"(\.$)");
        new_id = regex_replace(new_id, check_dot, "");
    }
    
    // 7단계 : 2자 이하라면
    while(new_id.length() <= 2)
         new_id += new_id[new_id.length() - 1];

    return new_id;
}

string solution(string new_id) {
    string answer = "";
    
    answer = preprocessor(new_id);
    
    return answer;
}

/*
3 <= 아이디 길이 <= 15
규칙 : 알파벳 소문자, 숫자, -, _, .
. = 처음과 끝에 사용 못함, 연속 사용 못함

7단계를 거침
1단계 -> 모든 대문자를 소문자로 치환
2단계 -> 규칙에 해당하는 문제 제외 제거
3단계 -> 2번 이상 연속된 .을 1개로 치환
4단계 -> .이 처음이나 끝에 있으면 제거
5단계 -> 비어있으면 a를 대입
6단계 -> 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자들을 제거
7단계 -> 2자 이하라면, 마지막 문자를 길이 3이 될 때까지 붙임

* 정규표현식 : regex pattern_name(pattern)
 regex_match(text, pattern); -> 매칭 확인
 regex_search(text, storage, pattern); -> 매칭 되는 걸 저장
 regex_replace(text, pattern, replace_word) -> 패턴 중 해당되는 걸 치환
 
 pattern
 . : 임의의 한 문자
 * : 앞의 요소가 0번이상 반복됨
 + : 앞의 요소가 1번이상 반복됨
 ? : 앞의 요소가 0번 또는 1번 나타남
 \d : 숫자
 \w : 알파벳, 숫자, _
 \s : 공백 문자
 \b : 단어의 시작과 끝을 구분
 [...] : 대괄호 안의 어떤 문자와 일치 -> 대괄호에선 -가 중간에 오면 범위로 인식하기 때문에 마지막에 넣어야 함
 [^...] : 대괄호 안의 문자를 제외한 어떤 문자와 일치
 ^ : 문자열 또는 줄의 시작 -> ^.$
 $ : 문자열 또는 줄의 끝 -> \.$
 a-zA-Z0-9
 \. : 특수문자의 경우 이스케이프를 붙여야 함
 {start, end} : 반복 횟수 지정
 R"()" : 문자열 리터럴이라고 부르는데 역슬래시를 많이 쓰다보면 헷갈리기 때문에 이 방법이 좋음
 | : or
*/