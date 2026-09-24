

class Solution {
    public int solution(int[] ingredient) {
        int result = 0;
        
        int[] temp = new int[ingredient.length];
        int lastIdx = 0;
        for (int num : ingredient) {
            temp[lastIdx++] = num;
            
            int find = this.getContainsCount(temp, lastIdx);
            lastIdx -= find * 4;
            result  += find;
        }
        
        return result;
    }
    
    private int getContainsCount(int[] arr, int lastIdx) {   
        int result = 0;
        
        while (true) {
            if (lastIdx < 4) return result;
            if (arr[lastIdx - 1] != 1) return result;
            if (arr[lastIdx - 2] != 3) return result;
            if (arr[lastIdx - 3] != 2) return result;
            if (arr[lastIdx - 4] != 1) return result;
            result++;
            lastIdx -= 4;
        }
    }
}

// 통과는 되는데, 시간이 매우 오래걸림
// 풀이 후 [다른 사람의 풀이] 참고했을 때 좋아보이는 방식 발견
// 배열의 lastIdx 값을 계속 최신화하면서 삭제가 아니라 lastIdx만 수정하는 방식
/*
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
*/

/*
1: 빵
2: 야채
3: 고기

[1 2 3 1]
*/