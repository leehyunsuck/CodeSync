// 1차 수정 - 태성씨 코드 보고 time 기준 for문이 더 적합하다고 판단해서 재작성
// 2차 수정 - LCM 공부 후 MAX값 설정 (예정)

import java.util.*;

class Solution {
    public int solution(int[][] signals) {
        int max = 20 * 20 * 20 * 20 * 20,
            signalCount = signals.length;

        for (int time = 1; time <= max; time++) {
            int yellowCount = 0;
 
            for (int[] signal : signals) {
                int green  = signal[0],
                    yellow = signal[1],
                    red    = signal[2],
                    all    = green + yellow + red;
                
                int target = time % all;
                // yellow 범위면
                if (green < target && target <= green + yellow) {
                    yellowCount++;
                } else {
                    break;
                }
            }
            
            if (yellowCount == signalCount) {
                return time;
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

7 % 4 = 3
green(2) + yellow(1) = 3

3/2/4 이면
1 2 3 [4] [5] 6 7 8 9 10 11 12 [13] [14] 15 16 17 18...

1 + green ~ yellow 반복
+ red

*/