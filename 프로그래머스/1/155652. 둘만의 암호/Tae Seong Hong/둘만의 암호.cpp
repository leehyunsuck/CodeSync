#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(char cs : s) {
        int count = 0;
        char change = cs;
        
        while(count < index) {
            change++;    
            
            if(change > 'z')
                change -= 26;
            
            if(skip.find(change) != string::npos)
                continue;
            
            count++;
        }
        
        answer += change;
    }
    
    return answer;
}


/*
s = 바꿀 문자열
skip = 쓰면 안되는 문자열
index = n만큼 뒤

z를 넘어가면 다시 a로
a = 97 / z = 122

* 최신 버전은 string.contains 로 문자열에 포함되어있는지 확인 가능함
* string::npos -> no position으로써 end처럼 찾지 못했을 때의 값임

*/