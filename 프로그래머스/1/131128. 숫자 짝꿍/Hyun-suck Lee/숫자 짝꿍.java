import java.util.*;

class Solution {
    public String solution(String X, String Y) {
        // 겹치는 것 탐색
        Map<Character, Integer> xMap = new HashMap<>();
        for (char c : X.toCharArray()) {
            xMap.merge(c, 1, Integer::sum);
        }
        
        Queue<Character> pQue = new PriorityQueue<>(Collections.reverseOrder());
        for (char c : Y.toCharArray()) {
            if (xMap.getOrDefault(c, 0) <= 0) continue;
            xMap.merge(c, -1, Integer::sum);
            pQue.offer(c);
        }
        
        // '0'만 여러개 있는 경우 처리
        while (pQue.size() > 1 && pQue.peek() == '0') {
            pQue.poll();
        }
        
        // 종합
        StringBuilder result = new StringBuilder();
        if (!pQue.isEmpty()) {
            while (!pQue.isEmpty()) {
                result.append(pQue.poll());
            }
        }
        
        return result.length() != 0 ? result.toString() : "-1";
    }
}