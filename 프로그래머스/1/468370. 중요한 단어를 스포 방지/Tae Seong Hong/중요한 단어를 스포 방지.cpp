#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;

    unordered_set<string> non_spoiler_word;
    vector<string> spoiler_word;

    int i = 0;

    while (i < message.length()) {
        if (message[i] == ' ') {
            i++;
            continue;
        }
        int start = i;

        while (i < message.length() && message[i] != ' ') {
            i++;
        }

        int end = i - 1;

        string temp = message.substr(start, end - start + 1);

        bool is_spoiler = false;

        for (int j = 0; j < spoiler_ranges.size(); j++) {
            if (start <= spoiler_ranges[j][1] &&
                end >= spoiler_ranges[j][0]) {

                is_spoiler = true;
                break;
            }
        }

        if (is_spoiler)
            spoiler_word.push_back(temp);
        else
            non_spoiler_word.insert(temp);
    }

    for (const string& word : spoiler_word) {

        if (non_spoiler_word.find(word) == non_spoiler_word.end()) {
            non_spoiler_word.insert(word);
            answer++;
        }
    }

    return answer;
}

/*
이전에 공개된 스포 방지 단어와 중복되면 안됨
스포 방지 구간을 클릭했을 때 모든 문자가 공개되면 -> 스포 방지 단어
어떤 스포 방지 구간에도 속하지 않는 모든 구간 -> 스포 방지 구간이 아닌 단어랑 겹치면 안 됨

message : 메시지 문자열
spoiler_ranges : 스포 방지 구간

* 첫 풀이
 나오는 모든 스포 방지 단어를 저장
 스포 방지 구간이 아닌 단어를 맵에서 삭제
 그러면 단어로 분리해서 순회
 count를 통해 스포일러 방지 구간에 속하는지 확인 후 스포 방지 단어에 저장
 
* 막힌 부분
 스포일러 방지 구간의 시작값이 단어 시작 앞일수도 있고 뒤일수도 있고
 따라서 그냥 두 구간을 비교하는 걸로는 안 됨
 if(count <= spoiler_ranges[i][0] && count <= spoiler_ranges[i][1])
 ex) count 0 ~ 8 spoiler_ranges 5 ~ 7
     count 0 ~ 5 spoiler_ranges 3 ~ 8
     count 3 ~ 5 spoiler_ranges 1 ~ 3
     이런 경우가 있다고 가정
     if(count <= spoiler_ranges[i][1] && count + temp.length() >= soiler_ranges[i][0])
     이러면? 
     0 <= 7 && 8 >= 5 true
     0 <= 8 && 5 >= 3 true
     3 <= 3 && 5 >= 1 true
     
* 또 막힌 부분
 here 중요 단어로 저장
 뒤에서 나옴 그럼 중요 단어가 아님
 
 phone은 중요 단어로 저장
 뒤에서 나올 때는 스포일러 방지 단어라서 저장이 가능함
 단 뒤에서 나온 phone은 저장 안됨 -> 앞에서 나왔기 때문
 
* 해석
 문제에서 왼쪽에서 오른쪽으로 였기에 spoiler_word는 벡터로 처리해서 큐 형식으로 저장
 처음에는 저번처럼 입력 스트림으로 바꿔 getline으로 진행했는데 문자열 바로 앞뒤에 공백이 있는지 없는지는 구분이 안됨
 그래서 문자열은 배열처럼 사용가능해서 배열처럼 진행
 substr로 단어를 뽑아오고, spoiler_word면 저장, 아니면 non_spoiler_word에 저장
 const string& word : spoiler_word에서 &는 복사해서 사용하는 것이 아닌 실제 객체를 사용해서 실행 시간을 줄일 수 있음
 단, 실제 값이 변경되면 안되기 때문에 const로 선언해줘야 함
 unordered 자료형의 find는 O(1) 임
 해당되는 값이 없으면 iterator가 end를 가르키게 됨
 그러면, 중요 단어인데 기존에 없던 값이기에 중요 단어가 됨
 여기서, 중요 단어로 한 번 나온 건 뒤에서 나오는 같은 중요 단어는 중요 단어가 아니게 됨
 그래서 추가해줘서 phone phone 같은 경우를 방지
*/