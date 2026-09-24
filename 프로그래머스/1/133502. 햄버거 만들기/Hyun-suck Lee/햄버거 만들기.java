class Solution {
    public int solution(int[] ingredient) {
        int result = 0;
        
        StringBuilder builder = new StringBuilder();
        for (int i : ingredient) {
            builder.append(i);
        }
        
        while (true) {
            int idx = builder.indexOf("1231");
            if (idx == -1) break;
        
            builder.replace(idx, idx + 4, "");
            
            result++;
        }
        
        return result;
    }
}

/*
1: 빵
2: 야채
3: 고기

[1 2 3 1]
*/