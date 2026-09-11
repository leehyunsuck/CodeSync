#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";
    string prev = "";
    
    for(int i=0;i<=s.length();i++) {
        if(s[i] == ' ' || i == s.length()) {
            if(num == "Z") {
                num = to_string(stoi("-1") * stoi(prev));
            }
            answer += stoi(num);
            prev = num;
            num = "";
            continue;
        }
        num += s[i];
    }
    return answer;
}

/*
문자열 = 숫자와 Z, 공백
"1 2 Z 3 " = 1 + 2 - 2 + 3
Z = 이전에 더한 숫자
*/