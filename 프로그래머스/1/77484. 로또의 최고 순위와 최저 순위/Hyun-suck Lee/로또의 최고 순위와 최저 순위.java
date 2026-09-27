import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] winNums) {
        Arrays.sort(winNums);
        
        int zeroCount  = 0,
            matchCount = 0;
        for (int num : lottos) {
            if (num == 0) {
                zeroCount++;
            } else if (Arrays.binarySearch(winNums, num) >= 0) {
                matchCount++;
            }
        }
  
        return new int[] {
            Math.min(6, 7 - (matchCount + zeroCount)), 
            Math.min(6, 7 - matchCount)
        };
    }
}

/*
1st. 6          7 - 6 = 1
2st. 5          7 - 5 = 2
... 
5st. 2          7 - 2 = 5
6st. 1, 0       7 - 1 = 6    7 - 0 = 7 -> 


0: 알아볼 수 없는 번호

return [당첨 가능 최고 순위, 최저 순위]
*/