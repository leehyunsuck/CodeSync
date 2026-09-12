import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        int maxRow = maps.length,
            maxCol = maps[0].length;
        
        // 0: 방문X , n: 최소 방문 수
        int[][] visited = new int[maxRow][maxCol];

        Queue<Robot> fifo = new LinkedList<>();
        fifo.add(new Robot(0, 0, 1));  // row, col, time
        
        while (!fifo.isEmpty()) {
            Robot now = fifo.remove();
            int vieistedTime = visited[now.row][now.col];
            
            if (vieistedTime != 0 && vieistedTime <= now.time) continue; // 최소 아님
            visited[now.row][now.col] = now.time;
            
            for (Robot next : now.getMoveNewRobot()) {
                if (next.isOver(0, 0, maxRow, maxCol)) continue; // 맵 이탈
                if (maps[next.row][next.col] == 0) continue;        // 벽
                fifo.add(next);
            }
        }
        
        int nmVisit = visited[maxRow - 1][maxCol - 1];
        return nmVisit == 0 ? -1 : nmVisit;
    }
}

// 필드 간단하게 public 으로 진행
class Robot {
    public static int[][] moveInfo = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상-하-좌-우
    public int row;
    public int col;
    public int time;
    
    public Robot(int row, int col, int time) {
        this.row  = row;
        this.col  = col;
        this.time = time;
    }
    
    public boolean isOver(int minR, int minC, int maxR, int maxC) {
        if (row < minR || row >= maxR) return true;
        if (col < minC || col >= maxC) return true;
        return false;
    }
    
    public Robot[] getMoveNewRobot() {
        int count = moveInfo.length,
            time  = this.time + 1;
        
        Robot[] robots = new Robot[count];
        for (int idx = 0; idx < count; idx++) {
            robots[idx] = new Robot(row + moveInfo[idx][0], col + moveInfo[idx][1], time);
        }
        
        return robots;
    }
}

/*
시작점 : 1, 1 (1-BASE)
목표지 : n, m (1-BASE)

return 최소_탐색_시간 or -1
*/