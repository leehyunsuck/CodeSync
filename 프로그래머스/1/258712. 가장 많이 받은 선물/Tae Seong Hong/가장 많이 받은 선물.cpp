#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, unordered_map<string, int>> gift_info;
    unordered_map<string, int> gift_count;
    unordered_map<string, int> gift_level;
    
    for(string gift : gifts) {
        stringstream ss(gift);
        
        string gift_receiver;
        string gift_sender;
        
        ss >> gift_sender >> gift_receiver;
        
        gift_info[gift_sender][gift_receiver]++;
        gift_level[gift_sender]++;
        gift_level[gift_receiver]--;
    }
    
    for(string sender : friends) {
        for(string receiver : friends) {
            // gift_info["muzi"]["ryan"] = 0 > gift_info["ryan"]["muzi"] = 3 -> no
            // 만약, 내가 더 많이 줬으면 내가 선물을 받아야 함
            if(gift_info[sender][receiver]  > gift_info[receiver][sender]) {
                gift_count[sender]++;
            } else if(gift_info[sender][receiver] == gift_info[receiver][sender]) {
                if(gift_level[sender] > gift_level[receiver])
                    gift_count[sender]++;
            }
        }
    }

    for (const auto& count : gift_count) {
    if (answer < count.second)
        answer = count.second;
}
    
    return answer;
}

/*
1대1 상황에선 내가 더 많이 준 경우
0대0 상황에선 선물 지수가 높은 사람
gifts A = 선물을 준 친구 / B = 선물을 받은 친구

* 풀이
 unordered_map 써서 각 이름별로 선물을 누구한테 선물을 받았는지 체크
 unordered_map<string, unordered_map<string, int>>

* for(const auto& count : gift_count) count.second
 map 자료형은 pair 형태로 저장되기 때문에
 first에는 key 값 second에는 value 값이 저장됨
*/