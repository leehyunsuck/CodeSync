import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        boolean[] isSkip = new boolean[26];
        for (char c : skip.toCharArray()) {
            isSkip[c - 'a'] = true;
        }
        
        List<Character> chars = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; c++) {
            if (isSkip[c - 'a']) continue;
            chars.add(c);
        }
        
        StringBuilder builder = new StringBuilder();
        for (char c : s.toCharArray()) {
            builder.append(chars.get((Collections.binarySearch(chars, c) + index) % chars.size()));
        }
        
        return builder.toString();
    }
}

// 97 ~ 122