#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int rows = park.size(),
        cols = park[0].size();
    
    for(int i=0;i<mats.size();i++) {       
        for(int row=0;row + mats[i] <= rows;row++) {
            for(int col=0;col + mats[i] <= cols;col++) {
                bool available = true;
                for(int check_row=row;check_row< row + mats[i];check_row++) {
                    for(int check_col=col;check_col< col + mats[i];check_col++) {
                        if(park[check_row][check_col] != "-1") {
                            available = false;
                            break;
                        }
                    }
                    if(!available)
                        break;
                }
                if(available) {
                    if(answer < mats[i])
                        answer = mats[i];
                }
            }
        }   
    }
    
    if(!answer)
        answer = -1;
    return answer;
}

/*
mats = 내가 가지고 있는 돗자리 크기
내가 가진 돗자리는 무조건 정사각형

park = 정보

 A  A -1  B  B  B  B -1
 A  A -1  B  B  B  B -1
-1 -1 -1 -1 -1 -1 -1 -1
 D  D -1 -1 -1 -1  E -1
 D  D -1 -1 -1 -1 -1  F
 D  D -1 -1 -1 -1 -1  F
 
map 내용
key 0 -> 1
key 1 -> 1
key 2 -> 8
key 3 -> 4
key 4 -> 5
key 5 -> 5

실패한 코드 -> 이유 : 열이 다를 때를 판단을 못함
이렇게 했던 이유 : 처음에 문제 풀기 전에는 mats x mats로 왼쪽 위부터 순회해서 계산하면 될거 같다고 생각하긴 했는데
그러면 for문이 너무 많아져서 아래처럼 풀어본건데 생각 못했던 문제가 있었음 -> 제출 채점에서 다 틀림 ㅋㅋ
for(int row=0;row<rows;row++) {
        int count = 0;
        for(int col=0;col<cols;col++) {
            if(park[row][col] == "-1")
                count++;
            else
                count = 0;
            
            if(available[row] < count)
                available[row] = count;
        }
    }
    
    for(int i=0;i<mats.size();i++) {
        int count = 0;
        int max_len = 0;
        for(int j=0;j<available.size();j++) {
            if(available[j] >= mats[i])
                count++;
            else
                count = 0;
            
            if(max_len < count)
                max_len = count;
        }
        
        if(max_len >= mats[i]) {
            answer = mats[i];
            break;
        }
    }
*/