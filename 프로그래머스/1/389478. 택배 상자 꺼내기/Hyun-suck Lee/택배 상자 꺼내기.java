class Solution {
    public int solution(int n, int w, int num) {
        int result = 1,
            numCol = -1; // num에 해당하는 column 인덱스 쓸거임
        
        int nowNum = 1;
        while (nowNum <= n) {
            // 우측으로
            for (int col = 0; col < w; col++) {
                if (nowNum > n) return result;
                if (numCol == col) result++;
                if (nowNum++ == num) numCol = col;
            }
            // 좌측으로
            for (int col = w - 1; col >= 0; col--) {
                if (nowNum > n) return result;
                if (numCol == col) result++;
                if (nowNum++ == num) numCol = col;
            }
        }
        
        return result;
    }
}