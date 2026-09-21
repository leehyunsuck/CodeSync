import java.util.*;

// 이번 목표
// 넘버 패드가 달라도
// 움직임이 달라도 
// 대응 가능하도록 

class Solution {
    private int[] thumb; // [좌, 우]
    private StringBuilder thumbLog;
    
    private NumberPad pad;
    
    // 판단용
    private boolean isForceLeft;
    private Set<Integer> onlyL;
    private Set<Integer> onlyR;
    
    public Solution() {
        this.pad = new NumberPad();
        this.thumb = new int[] {10, 11}; // *: 10, #: 11
        this.thumbLog = new StringBuilder();
        
        onlyL = new HashSet<>(Set.of(1, 4, 7));
        onlyR = new HashSet<>(Set.of(3, 6, 9));
    }
    
    public String solution(int[] numbers, String hand) {
        this.isForceLeft = hand.toLowerCase().equals("left");
        
        for (int num : numbers) {
            this.touchNumber(num);
        }
        
        return thumbLog.toString();
    }
    
    // 실제 터치 로직
    private void touchNumber(int number) {
        int idx;
        if      (this.onlyL.contains(number)) idx = 0;
        else if (this.onlyR.contains(number)) idx = 1;
        else {
            int lCnt = this.pad.findNumber(thumb[0], number),
                rCnt = this.pad.findNumber(thumb[1], number);
            
            idx = lCnt < rCnt || (lCnt == rCnt && isForceLeft) ? 0 : 1;
        }
        
        this.thumb[idx] = number;
        this.thumbLog.append(idx == 0 ? 'L' : 'R');
    }
}

class NumberPad {
    // 문제 상 기본값
    private static final int[][] DEFAULT_PAD = new int[][] {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 0, 11}
    };
    private static final int[][] DEFAULT_MOVE = new int[][] {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}    // 상 하 좌 우 순서임
    };
    
    private Map<Integer, List<Integer>> pad;
    
    public NumberPad() {
        this.setPad(NumberPad.DEFAULT_PAD, NumberPad.DEFAULT_MOVE);
    }
    
    // bfs로 최소 탐색 
    public int findNumber(int now, int target) {
        int result = 0;
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {now, 0}); // [위치, 이동_횟수]
        
        boolean[] visited = new boolean[pad.size() + 1];
        while (!queue.isEmpty()) {
            int[] info = queue.poll();
            
            if (visited[info[0]]) continue;
            visited[info[0]] = true;
            
            if (info[0] == target) return info[1];  // 모든 거리가 1이니까 지금 발견되는게 최소값임
            
            for (int next : pad.get(info[0])) {
                if (visited[next]) continue;
                queue.offer(new int[] {next, info[1] + 1});
            }
        }
        
        return -1;
    }
    
    public void setPad(int[][] arrPad, int[][] moves) {
        this.pad = new HashMap<>();
        
        // 모든 키패드 탐방해서 이동 가능 경로 pad 그래프 설정
        for (int row = 0; row < arrPad.length; row++) {
            for (int col = 0; col < arrPad[0].length; col++) {
                int num = arrPad[row][col];
                    
                for (int[] move : moves) {
                    int moveRow = row + move[0],
                        moveCol = col + move[1];
                    
                    if (moveRow < 0 || moveCol < 0) continue;
                    if (moveRow >= arrPad.length || moveCol >= arrPad[0].length) continue;
                    
                    if (!this.pad.containsKey(num)) {
                        this.pad.put(num, new ArrayList<>());
                    }
                    this.pad.get(num).add(arrPad[moveRow][moveCol]);
                }
            }
        }
    }
    
}



/*
      
    1 2 3
    4 5 6
    7 8 9
    * 0 #

좌측 엄지 시작: *
우측 엄지 시작: #

- 상 하 좌 우 4방향으로만 이동 가능
- 1, 4, 7 --> 좌측만
- 3, 6, 9 --> 우측만
- 가운데 키패드 --> 더 가까운 -> (같다면) -> 주 손잡이 손가락

*/