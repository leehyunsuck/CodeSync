#include <string>
#include <vector>

using namespace std;

int max(int a, int b) {
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if(a>b)
        return b;
    else
        return a;
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while(1) {
        int min_bill = min(bill[0], bill[1]);
        int max_bill = max(bill[0], bill[1]);
        int min_wallet = min(wallet[0], wallet[1]);
        int max_wallet = max(wallet[0], wallet[1]);
        if(min_bill > min_wallet || max_bill > max_wallet) {
            if(bill[0] > bill[1])
                bill[0] /= 2;
            else {
                bill[1] /= 2;
            }
            answer++;
            continue;
        }
        break;
    }
    
    return answer;
}

/*
길이가 긴 쪽을 반으로
홀수(odd) 였다면 소수점 이하는 버림
90도 돌려서 사용가능하면 끝
*/