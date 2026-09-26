import java.util.*;

class Solution {
    // 모든 배열 1base임
    public int solution(int n, int[] lost, int[] reserve) {
        boolean[] canBorrow = new boolean[n + 2],   // 앞 뒤 비교해야함
                  isLost    = new boolean[n + 2];
        
        for (int idx : lost) {
            isLost[idx] = true;
        }
        
        for (int idx : reserve) {
            canBorrow[idx] = true;
            
            if (isLost[idx]) {  // 잃어버렸는데 여분이 있는 경우 -> 못빌려줌
                isLost[idx] = false;
                canBorrow[idx] = false;
            }
        }
        
        int result = 0;
        for (int idx = 1; idx <= n; idx++) {
            boolean haveOrBorrow = !isLost[idx];
            
            if (!haveOrBorrow) {
                if (canBorrow[idx - 1]) {
                    canBorrow[idx - 1] = false;
                    haveOrBorrow = true;
                }
                else if (canBorrow[idx + 1]) {
                    canBorrow[idx + 1] = false;
                    haveOrBorrow = true;
                }
            }
            
            if (haveOrBorrow) {
                result++;
            }
        }
        
        return result;
    }
}

/*
바로 앞번호 or 바로 뒷번호 
*/