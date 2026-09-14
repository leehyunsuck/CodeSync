import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        Map<String, Integer> scores = new HashMap<>();
        for (int idx = 0; idx < name.length; idx++) {
            scores.put(name[idx], yearning[idx]);
        }
        
        int[] result = new int[photo.length];
        for (int idx = 0; idx < photo.length; idx++) {
            for (String p : photo[idx]) {
                result[idx] += scores.getOrDefault(p, 0);
            }
        }
        
        return result;
    }
}