#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> comp;
    
    for(string complete : completion) {
        comp[complete] += 1;
        }
    
    for(string part : participant) {
        if(comp[part] != 0) {
            comp[part] -= 1;
        } else { 
            answer = part;
            break;
            }
        }
        
    return answer;
}

/*
participant = 참가 선수
completion = 완주한 선수

동명이인이 있을수도 있음
완주 못한 선수는 무조건 한 명
*/