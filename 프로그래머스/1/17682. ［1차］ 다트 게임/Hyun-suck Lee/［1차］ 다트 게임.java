class Solution {
    public int solution(String dartResult) {
        int result = 0,
            before = 0,
            now    = 0;
        
        char[] arr = dartResult.toCharArray();
        for (int idx = 0; idx < arr.length; idx++) {
            char c = arr[idx];
            
            // 숫자
            if ('0' <= c && c <= '9') {
                result += before;
                before  = now;
                now     = c - '0';
                
                if (arr[idx + 1] == '0') {
                    now *= 10;
                    idx++;
                }
                
                continue;
            }
            
            // 보너스 or 옵션
            if      (c == 'S') now  = now;
            else if (c == 'D') now *= now;
            else if (c == 'T') now *= now * now;
            else if (c == '#') now *= -1;
            else if (c == '*') {
                now    *= 2;
                before *= 2;
            }
        }
        result += before + now;
        
        return result;
    }
}

/*
얻을 수 있는 점수: 0 ~ 10 

S, D, T 는 각 점수 1, 2, 3 제곱

옵션:
- *: 해당 및 바로 이전 점수 2배로
- #: 해당 점수 마이너스
*/