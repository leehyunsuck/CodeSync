import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> nameCount = new HashMap<>();
        nameCount.merge(participant[participant.length - 1], 1, Integer::sum);
        for (int idx = 0; idx < completion.length; idx++) {
            this.zeroRemoveElseAdd(nameCount, 1, participant[idx]);
            this.zeroRemoveElseAdd(nameCount, -1, completion[idx]);
        }
        
        return nameCount.keySet().toArray(new String[0])[0];
    }
    
    private void zeroRemoveElseAdd(Map<String, Integer> map, int add, String key) {
        if (map.containsKey(key) && map.get(key) + add == 0) {
            map.remove(key);
        } else {
            map.merge(key, add, Integer::sum);
        }
    }
}