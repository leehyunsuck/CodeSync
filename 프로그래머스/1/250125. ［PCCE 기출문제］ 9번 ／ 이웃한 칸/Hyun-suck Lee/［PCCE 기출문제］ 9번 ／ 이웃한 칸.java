class Solution {
    private static final int[][] MOVES = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    public int solution(String[][] board, int row, int col) {
        int result = 0;
        
        String target = board[row][col];
        for (int[] move : Solution.MOVES) {
            int checkRow = row + move[0],
                checkCol = col + move[1];
            
            if (checkRow < 0 || checkCol < 0) continue;
            if (checkRow >= board.length || checkCol >= board[0].length) continue;
            if (!target.equals(board[checkRow][checkCol])) continue;
            result++;
        }
        
        return result;
    }
}