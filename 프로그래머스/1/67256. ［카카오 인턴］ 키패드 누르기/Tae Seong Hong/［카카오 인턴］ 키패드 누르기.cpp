#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int calc_dist(int hand_pos, int find_num) {
    // 행과 열 위치를 구하기
    // 거리는 최근에 풀었던 문제 바탕화면 정리에 거리 구하는 공식이 있음
    // |rdx - lux| + |rdy - luy|
    pair<int, int> hand = make_pair((hand_pos - 1) / 3, (hand_pos - 1) % 3);
    pair<int, int> find = make_pair((find_num - 1) / 3, (find_num - 1) % 3);
    
    return abs(hand.first - find.first) + abs(hand.second - find.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_hand = 10,
        right_hand = 12;
        
    for(int number : numbers) {
        if(number == 0)
            number = 11;
        
        if(number % 3 == 1) { // 1 4 7
            answer += "L";
            left_hand = number;
        } else if(number % 3 == 0) { // 3 6 9
            answer += "R";
            right_hand = number;
        } else { // 2 5 8 0(11)
            int left_dist = calc_dist(left_hand, number),
                right_dist = calc_dist(right_hand, number);
            
            if(left_dist < right_dist) {
                answer += "L";
                left_hand = number;
            } else if(right_dist < left_dist) {
                answer += "R";
                right_hand = number;
            } else {
                if(hand == "left") {
                    answer += "L";
                    left_hand = number;
                } else {
                    answer += "R";
                    right_hand = number;
                }
            }
            
        }
    }
    
    return answer;
}

/*
* 시작
왼손 = *
오른손 : #

손가락은 상하좌우로만 이동 가능함
1 4 7 = 왼손
3 6 9 = 오른손
2 5 8 0 = 더 가까운 손 / 거리가 같으면 오른손잡이 or 왼손잡이인지에 따라 다름

numbers : 순서대로 누를 번호
hand : 왼손/오른손 잡이
result : 어떤 걸로 눌렸는지

left : 5
right : 9
왼손잡이면 L -> 8

// 처음 시도한 방법
// 문제는 0에서 나오는 경우 값이 매우 틀리게 됨 11 - 1 -> 10
int calc_dist(int hand_pos, int find_num) {
    int dist = abs(hand_pos - find_num);
    if(dist % 3 == 0)
        return dist / 3;
    else if(dist == 1)
        return 1;
    else if(dist % 2 == 0)
        return 2;
    else
        return 3;
}
*/