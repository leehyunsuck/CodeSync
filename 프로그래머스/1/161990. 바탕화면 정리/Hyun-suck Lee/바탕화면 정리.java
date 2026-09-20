class Solution {
    public int[] solution(String[] wallpaper) {
        int[] result = {        
            Integer.MAX_VALUE,  // minRow
            Integer.MAX_VALUE,  // minCol
            Integer.MIN_VALUE,  // maxRow
            Integer.MIN_VALUE   // maxCol
        };
            
        for (int row = 0; row < wallpaper.length; row++) {
            for (int col = 0; col < wallpaper[0].length(); col++) {
                if (wallpaper[row].charAt(col) != '#') continue;
                
                result[0] = Math.min(result[0], row);       // 좌 드래그
                result[1] = Math.min(result[1], col);       
                result[2] = Math.max(result[2], row + 1);   // 우 드래그
                result[3] = Math.max(result[3], col + 1);
            }
        }
        
        return result; 
    }
}

/*
최소 row, col
최대 row, col을 찾아야하는 문제 같음
*/