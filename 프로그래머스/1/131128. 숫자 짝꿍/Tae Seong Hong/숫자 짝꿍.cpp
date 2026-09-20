#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    unordered_map<char, int> X_map;
    unordered_map<char, int> Y_map;
    multiset<char, greater<char>> jjak;
    
    for(char x : X)
        X_map[x]++;
    
    for(char y : Y)
        Y_map[y]++;
    
    for(const auto& pair : X_map) {
        int count = min(X_map[pair.first], Y_map[pair.first]);
        
        if(count == 0)
            continue;
        
        for(int i=0;i<count;i++)
            jjak.insert(pair.first);
    }
    
    if(!jjak.empty()) {
        for(const auto& jak : jjak) {
            if(answer == "0")
                continue;
            answer += jak;    
        }
    } else
        answer = "-1";

    return answer;
}

/*
짝꿍 = 공통된 수 / 자릿 수 상관 x
짝꿍이 없으면 -1
0만 있으면 0


*/