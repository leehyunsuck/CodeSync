import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        KVMap<String, Integer> kvMap = new KVMap();
        for (int idx = 0; idx < players.length; idx++) {
            kvMap.put(players[idx], idx);
        }
        
        for (String rankUpUser : callings) {
            int userRank = kvMap.getValue(rankUpUser);
            String rankDownUser = kvMap.getKey(userRank - 1);
        
            kvMap.put(rankUpUser, userRank - 1);
            kvMap.put(rankDownUser, userRank);
        }
        
        String[] result = new String[players.length];
        for (Map.Entry<String, Integer> entry : kvMap.entrySetKV()) {
            result[entry.getValue()] = entry.getKey();
        }
        
        return result;
    }
}

// Key Value 모두 고유값인 자료구조 있을만한데 -> 풀이 후 찾아보기
// 사용하는 기능들만 구현 (remove 등 구현 안했음)
class KVMap<T1, T2> {
    private Map<T1, T2> kMap;
    private Map<T2, T1> vMap;
    
    public KVMap() {
        this.kMap = new HashMap<>();
        this.vMap = new HashMap<>();
    }
    
    public void put(T1 key, T2 value) {
        kMap.put(key, value);
        vMap.put(value, key);
    }
    
    public T2 getValue(T1 key) {
        return kMap.get(key);
    }
    
    public T1 getKey(T2 value) {
        return vMap.get(value);
    }
    
    public Set<Map.Entry<T1, T2>> entrySetKV() {
        return kMap.entrySet();
    }
}

// 추월한 선수 이름 부름
// return 1등 선수 이름부터 쭉 나열

