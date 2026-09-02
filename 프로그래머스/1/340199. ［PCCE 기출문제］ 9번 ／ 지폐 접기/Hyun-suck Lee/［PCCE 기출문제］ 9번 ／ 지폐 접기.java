class Solution {
    public int solution(int[] wallet, int[] bill) {
        int answer = 0;
        this.order(wallet);
        
        while (true) {
            order(bill);
            if (checkFit(wallet, bill)) break;
            
            bill[1] >>= 1;
            answer++;
        }
        
        return answer;
    }

    private boolean checkFit(int[] space, int[] thing) {
        return space[0] >= thing[0] && space[1] >= thing[1];
    }
    
    // 원소 개수 2개로 정해졌으므로 편하게 스왑으로
    private void order(int[] target) {
        if (target[0] > target[1]) {
            int temp = target[0];
            target[0] = target[1];
            target[1] = temp;
        }
    }
}