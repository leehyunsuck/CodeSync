class Solution {
    public int solution(String s) {
        int answer = 0;
        
        int before = 0;
        for (String strNum : s.split(" ")) {
            if (strNum.equals("Z")) {
                answer -= before;
                continue;
            }
            
            int now = Integer.parseInt(strNum);
            
            answer += now;
            before = now;
        }
        
        return answer;
    }
}

// 숫자를 차례대로 더함
// Z가 나오면 바로 전에 더했던 숫자 뺌

