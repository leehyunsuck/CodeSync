import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        // 그래프 설정
        List<List<Integer>> graph = new ArrayList<>();
        for (int node = 0; node < n; node++) {
            graph.add(new ArrayList<>());
        }
        
        for (int i = 0; i < computers.length; i++) {
            int[] computer = computers[i];
            
            List<Integer> node = graph.get(i);
            for (int j = 0; j < computer.length; j++) {
                if (i == j)           continue;
                if (computer[j] == 0) continue;
                node.add(j);
            }
        }
        
        // 로직 시작
        int result = 0;
        
        boolean[] visited = new boolean[n];
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            result++;
            
            Queue<Integer> queue = new LinkedList<>();
            queue.add(node);
            
            while(!queue.isEmpty()) {
                int now = queue.remove();
                
                if (visited[now]) continue;
                visited[now] = true;
                
                for (int next : graph.get(now)) {
                    if (visited[next]) continue;
                    queue.add(next);
                }
            }
        }
        
        return result;
    }
}

/*
A <-> B <-> C 
A-B-C [OK]

n : PC 개수
computers : computers[i][i] (자기자신)은 항상 1
          : computers[i][j] 이 1이면 연결 된 상태
          
return 네트워크의 개수
*/