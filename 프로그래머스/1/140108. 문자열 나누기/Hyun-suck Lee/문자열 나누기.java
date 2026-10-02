class Solution {
    public int solution(String s) {
        int result = 0;
        
        char firstChar = ' ';
        int  firstCount = 0,
             otherCount = 0;
        for (char c : s.toCharArray()) {
            if (firstChar == ' ') {
                firstChar = c;
                firstCount = 1;
                otherCount = 0;
                continue;
            }
            
            if (c == firstChar) {
                firstCount++;
            } else {
                otherCount++;
            }
            
            if (firstCount == otherCount) {
                firstChar = ' ';
                result++;
            }
        }
        
        if (firstChar != ' ') {
            result++;
        }
        
        return result;
    }
}


