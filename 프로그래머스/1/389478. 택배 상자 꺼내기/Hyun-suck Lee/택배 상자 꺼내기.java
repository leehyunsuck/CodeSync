class Solution {
    public int solution(int n, int w, int num) {
        int result = 1;
        
        boolean isRight = true;
        // col 은 nowNum 인덱스고 numCol은 num에 해당하는 인덱스임
        for (int nowNum = 1, col = 0, numCol = -1; nowNum <= n; nowNum++) {
            if (numCol == col) result++;
            if (nowNum == num) numCol = col;
            
            col += isRight ? 1 : -1;
            if (col == -1 || col == w) {
                isRight = !isRight;
                col += isRight ? 1 : -1;    // 끝쪽은 같은 인덱스 한번 더 써야됨
            }
        }
        
        return result;
    }
}