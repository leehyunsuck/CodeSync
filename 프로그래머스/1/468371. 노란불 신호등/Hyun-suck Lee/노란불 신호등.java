import java.util.*;

class Solution {
    private void addCounting(int[] where, int idx, int when) {
        for (; when > 0; when--) {
            where[idx++]++;
        }
    }
    
    public int solution(int[][] signals) {
        // LCM 계산 수식 모름 ㅇㅅㅇ...
        // 이거는 수학을 몰라서 아몰랑 해버렸는데 통과 되더라고 (1레벨 문제라 최적화까지 요구 안했나봄)
        int max = 20 * 20 * 20 * 20 * 20;   

        // max + 1 한 이유는 이중for문 안에 보면 timeSlice를 계산 편하게 1 부터 시작하게 했기 때문
        int[] yellowTimes = new int[max + 1];
        
        for (int idx = 0; idx < signals.length; idx++) {
            int green  = signals[idx][0],
                yellow = signals[idx][1],
                red    = signals[idx][2];

            // yellow 구간만 계산했음
            for (int timeSlice = 1; timeSlice <= max;) {
                // 이거 addCounting에 최대값 넘는경우에 대한 차단을 안해서 여기서 차단했는데
                // 생각해보니 여기 말고 addCounting에서 하는게 맞을듯?
                if (timeSlice + green + yellow > max) break; 
                timeSlice += green;
                addCounting(yellowTimes, timeSlice, yellow);
                timeSlice += yellow + red;
            }
        }
        
        int sCount = signals.length;
        for (int idx = 0; idx < yellowTimes.length; idx++) {
            if (sCount == yellowTimes[idx]) {
                return idx;
            }
        }

        return -1;
    }
}

/*
n: 도로에 배치된 차량 신호등 개수
신호등 순서: green -> yellow -> red  
지속 시간: 신호등 마다 다름 (1sec ~ 18sec)
처음: 무조건 green (signals)

G+Y+R 은 20보다 작음 400까지만 하면 되나?

return: 모든 신호등이 노란불이 되는 가장 빠른 시각 or -1


2/1/1 이면
1 2 [3] 4 5 6 [7] 8 9 10 [11] ...

3/2/4 이면
1 2 3 [4] [5] 6 7 8 9 10 11 12 [13] [14] 15 16 17 18...

1 + green ~ yellow 반복
+ red

*/