import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        Set<Character> skipSet = new HashSet<>();
        for (char c : skip.toCharArray()) {
            skipSet.add(c);
        }
        
        StringBuilder builder = new StringBuilder();
        for (char c : s.toCharArray()) {
            for (int count = 0; count < index; count++) { 
                if (++c > 122) {
                    c = (char) (97 + (c % 123));
                }
                if (skipSet.contains(c)) count--;
                
            }
            builder.append(c);
        }
        
        return builder.toString();
    }
}
/*
s의 각 알파벳을 index 만큼 뒤 알파벳으로 변경
(단, z 넘어가면 a로 돌아감)

skip 알파벳 제외

97 ~ 122
*/