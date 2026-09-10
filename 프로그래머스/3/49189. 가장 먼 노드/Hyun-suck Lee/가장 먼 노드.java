import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        List<List<Integer>> graph = new ArrayList<>(); // 1base
        for (int idx = 0; idx <= n; idx++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edge) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        int[] minVisit = new int[n + 1]; // 1base
        for (int idx = 0; idx <= n; idx++) {
            minVisit[idx] = Integer.MAX_VALUE;
        }
        
        Queue<int[]> queue = new LinkedList<>(); // [노드, 시간] 으로 사용
        queue.add(new int[] {1, 0});    
        
        int maxTime = 0;
        while(!queue.isEmpty()) {
            int[] node = queue.remove();
            int now  = node[0],
                time = node[1];
            
            if (minVisit[now] <= time) continue;
            minVisit[now] = time;
            
            if (time > maxTime) {
                maxTime = time;
            }
            
            for (int next : graph.get(now)) {
                // BFS + 모든 엣지 시간 동일하므로 이미 방문여부 이걸로 판단
                if (minVisit[next] != Integer.MAX_VALUE) continue;
                queue.add(new int[] {next, time + 1});
            }
        }
        
        int result = 0;
        for (int time : minVisit) {
            if (time != maxTime) continue;
            result++;
        }
        
        return result;
    }
}
/*
양방향 그래프

1번 노드에서 가장 멀리 떨어진 노드의 개수
- 최단 경로 기준

*/