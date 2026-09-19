import java.util.*;

class Solution {
    public int[] solution(String[] park, String[] routes) {
        return new RobotDog(park)
                    .runCommands(routes)
                    .getNow();
    }
}

class RobotDog {
    private static final Map<Character, int[]> MOVE_MAP = Map.of(
        'E', new int[] {0, 1}, 'W', new int[] {0, -1},
        'S', new int[] {1, 0}, 'N', new int[] {-1, 0}
    );
    private static final char START_BLOCK = 'S';
    private static final char WALL_BLOCK  = 'X';
    
    private int[]    now;
    private char[][] park;
    
    public RobotDog(String[] park) {
        this.setPark(park); // 하면서 this.now도 
    }
    
    public RobotDog runCommands(String[] commands) {
        for (String command : commands) {
            this.runCommand(command);
        }
        
        return this;
    }
    
    public RobotDog runCommand(String command) {
        char[] c = command.toCharArray(); // {'방향', ' ', '몇칸'}  
        
        int[] direction = RobotDog.MOVE_MAP.get(c[0]);
        int   count     = c[2] - '0';
        
        if (canCommand(direction, count)) {
            this.now[0] += (direction[0] * count);
            this.now[1] += (direction[1] * count);
        }
        
        return this;
    }
    
    public boolean canCommand(int[] direction, int count) {
        int[] tempNow  = new int[] {this.now[0], this.now[1]};
   
        for (; count > 0; count--) {
            tempNow[0] += direction[0];
            tempNow[1] += direction[1];
            
            // 맵 이탈
            if (tempNow[0] < 0 || 
                tempNow[1] < 0 ||
                tempNow[0] >= this.park.length || 
                tempNow[1] >= this.park[0].length) 
                return false;
            
            // 벽
            if (this.park[tempNow[0]][tempNow[1]] == RobotDog.WALL_BLOCK) return false;
        }
        
        return true;
    }
    
    public int[] getNow() {
        return this.now;
    }
    
    public RobotDog setPark(String[] park) {
        this.park = new char[park.length][park[0].length()];
        
        for (int row = 0; row < park.length; row++) {
            for (int col = 0; col < park[row].length(); col++) {
                this.park[row][col] = park[row].charAt(col);
                
                if (this.park[row][col] != RobotDog.START_BLOCK) continue;
                this.now = new int[] {row, col};
            }
        }
        
        return this;
    }
}

/*
[S] 시작 지점
[O] 이동 가능
[X] 장애물

E W S N / 동 서 남 북 으로만 이동

return 최종 위치
*/