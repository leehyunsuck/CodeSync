#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
    
    Date(string today) {
        year = stoi(today.substr(0, 4)); 
        month = stoi(today.substr(5, 2));
        day = stoi(today.substr(8, 2));
    }
};

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string, int> term_info;
    Date t_date(today);
    int index = 1;
    
    for(string term : terms)
        term_info[term.substr(0, 1)] = stoi(term.substr(2));

    for(string privacie : privacies) {
        Date p_date(privacie.substr(0, 10));
        p_date.month += term_info[privacie.substr(11)];
        
        while(p_date.month > 12) {
            p_date.year += 1;
            p_date.month -= 12;
        }
        
        int p_sum = p_date.year * 10000 + p_date.month * 100 + p_date.day;
        int t_sum = t_date.year * 10000 + t_date.month * 100 + t_date.day;
        
        if(p_sum <= t_sum)
            answer.push_back(index);
        
        index++;
    }
    
    
    return answer;
}

/*
terms(A 6 / B 12 ...) = 약관/기간
privaices(date A ...) = 수집일자/약관

오늘이 privaices[0] + 약관 보다 큰지

* 헷갈렸던 점
 개인정보 수집일자는 약관이 지난 뒤 -1일까지 보관 가능함
 굳이 -1까지 안하고 오늘 <= 개인정보 수집일자 로 보면 될듯
 
 privacie.substr(10)으로 해버려서 앞에 공백 안 보여서 5분 정도 헤맴
 substr(9)로 출력해보고 11라는 걸 깨달음
 
 처음 설계하다가 day가 필요 없는 줄 알고 뺐다가 테스트 돌려보고 생각해보니까 일자도 비교해야 되서 다시 넣음
 값이 또 이상해서 확인해보니까 오늘 <= 개인정보 수집일자가 아니고 오늘 >= 개인정보 수집일자 였음
*/