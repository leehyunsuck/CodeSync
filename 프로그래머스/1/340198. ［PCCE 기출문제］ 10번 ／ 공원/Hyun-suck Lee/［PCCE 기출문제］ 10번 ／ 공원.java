class Solution {
    public int solution(int[] mats, String[][] park) {
        int result = -1;
        
        for (int mat : mats) {
            if (!canSpread(mat, park)) continue;
            result = mat > result ? mat : result;
        }
        
        return result;
    }
    
    private boolean canSpread(int mat, String[][] park) {
        for (int row = 0; row + mat <= park.length; row++) {
            for (int col = 0; col + mat <= park[0].length; col++) {
                if (!park[row][col].equals("-1")) continue;
                if (!canSpread(mat, row, col, park)) continue;
                
                return true;
            }
        }
        
        return false;
    }
    
    private boolean canSpread(int mat, int row, int col, String[][] park) {
        for (int r = row; r < row + mat; r++) {
            for (int c = col; c < col + mat; c++) {
                if (park[r][c].equals("-1")) continue;
                return false;
            }
        }
        
        return true;
    }
}