#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, set<string>> report_info;
    
    
    for(string s : report) {
        stringstream ss(s);
        
        string report_sender;
        string report_receiver;
        
        ss >> report_sender >> report_receiver;
        
        report_info[report_receiver].insert(report_sender);
    }
    
    for(auto info : report_info) {
        if(info.second.size() >= k) {
            for(string sender : info.second) {
                auto it = find(id_list.begin(), id_list.end(), sender);
                int index = it - id_list.begin();
                answer[index]++;
            }
        }
    }
        
    return answer;
}

/*
- 문제
한 번에 한 명의 유저를 신고 가능함
무한 신고 가능함
한 유저 여러 번 신고 가능하지만 누적 1회로 처리
k번 이상 신고되면 게시판 사용 불가, 신고한 유저에게 메일로 안내

id_list = 유저 id / 중복 x
report = [누가 누구를]
k = 정지 기준

- 어떻게 풀어볼 것인가
1) map과 set을 이용하면 쉽게 풀 수 있을 것 같음
   -> 다만 c++에서의 map, set 사용 방법을 모름
2) key를 당한사람, value를 신고자 저장 / value 개수 세서 k 이상이면 value에 있는 사람들로 result 배열 생성
3) value는 신고자가 똑같은 사람일 수도 있으니 set 사용
4) report의 값은 split으로 나누면 될 거 같음 -> 이것도 사용 방법 찾아봐야 함

- 정리
* vector에 값을 넣는 방법 - insert를 사용함
 vec.insert(넣을 위치, 넣을 값, 크기)
 넣을 위치는 std::next(vec.begin(), 몇번째로 이동) / vec.begin() - 처음 위치 / vec.end() - 맨 뒤
 넣을 값은 arr, arr + 배열크기 - 배열 삽입  / {601, 602} - 값 자체 / c2.begin(), c2.end() - 다른 벡터
 
* map 사용 방법 - <map> 헤더 필요
 선언 - map<타입, 타입> 이름; // ex) map<string, vector<string>> name;
 삽입 - map.insert({"key", value});
       key가 없으면 자동으로 생성해줌 즉, map.insert["key"].insert("value") 으로도 바로 사용가능함
 출력 - map["key"][0]; // 리스트의 경우
 개수 - map.size(); // 키의 개수
 찾기 - map.count("key") // key가 있으면 1 없으면 0

* set 사용 방법 - <set> <algorithm> 헤더 필요
 선언 - set<type> 이름; // ex) set<string> name;
 삽입 - set.insert("value");
 출력 - for_each(set.cbegin(), set.cend(), [](type x))  / 아마 더 좋은 방법이 있을 수도
 개수 - set.size();

* split 방법 - <sstream> 헤더 필요
 stringstream ss(문자열); // 문자열을 입력 스트림처러 다루게 해줌
 string temp; // 임시 저장용
 vector<string> 결과변수;
 while(getline(ss, temp, '구분자')) { // getline이 입력값으로 stream을 받음
    result.push_back(temp); // 벡터 맨 뒤에 값을 추가하는 함수 -> 이런게 있었네
 }
 for(string s : result)
    cout << s << " ";
    
* stream 사용법
 stream으로 변경하게 되면 cin 처럼 입력으로 사용 가능함
 즉, ss >> 신고자 >> 신고받은 사람 으로 처리할 수도 있음!
*/