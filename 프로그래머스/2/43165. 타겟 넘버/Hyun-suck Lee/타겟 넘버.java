class Solution {
    public int solution(int[] numbers, int target) {
        return dfs(numbers, target, 0, 0);
    }
    
    public int dfs(int[] numbers, int target, int num, int idx) {
        if (idx == numbers.length) {
            return num == target ? 1 : 0;
        }

        return dfs(numbers, target, num + numbers[idx], idx + 1) 
             + dfs(numbers, target, num - numbers[idx], idx + 1); 
    }
}