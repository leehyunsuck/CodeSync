#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> score_map;
    
    for(int i=0;i<name.size();i++) {
        score_map[name[i]] = yearning[i];
    }
    
    for(int i=0;i<photo.size();i++) {
        int sum = 0;
        for(int j=0;j<photo[i].size();j++) {
            if(score_map[photo[i][j]] != 0) {
                sum += score_map[photo[i][j]];
            }
        }
        answer.push_back(sum);
    }
    
    return answer;
}

/*
name = 그리워하는 사람
yearning = 각 사람별 그리움 점수
photo = 각 사진에 찍힌 인물

may kein kain radi = 19
may kein = 10 + 5 = 15
*/