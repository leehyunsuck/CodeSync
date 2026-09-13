import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        return dfs(begin, target, words, new boolean[words.length], 0);
    }
    
    public int dfs(String now, String target, String[] words, boolean[] used, int count) {
        if (now.equals(target)) return count;
        
        int[] success = new int[words.length];
        for (int idx = 0; idx < used.length; idx++) {
            if (used[idx]) continue;
            
            int diff = 0;
            for (int i = 0; i < now.length() && diff < 2; i++) {
                if (now.charAt(i) != words[idx].charAt(i)) {
                    diff++;
                }
            }
            if (diff != 1) continue;
            
            used[idx] = true;
            success[idx] = dfs(words[idx], target, words, used, count + 1);
            used[idx] = false;
        }
        
        int min = Integer.MAX_VALUE;
        for (int c : success) {
            if (c == 0) continue;
            min = Math.min(min, c);
        }
        
        return min == Integer.MAX_VALUE ? 0 : min;
    }
}