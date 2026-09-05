import java.util.*;

class Solution {
    private boolean isSection(BitSet bit, int start, int end) {
        for (int idx = start; idx <= end; idx++) {
            if (bit.get(idx)) return true;
        }
        
        return false;
    }
    
    public int solution(String message, int[][] spoilerRanges) {
        BitSet spoilerBit = new BitSet(message.length());
        for (int[] spoiler : spoilerRanges) {
            for (int idx = spoiler[0]; idx <= spoiler[1]; idx++) {
                spoilerBit.set(idx);
            }
        }
        
        Set<String>   openWord    = new HashSet<>();
        Queue<String> spoilerWord = new LinkedList<>();
        
        // 공개, 스포일러 단어 구분
        int msgStart = 0;
        for (String msg : message.split(" ")) {
            int msgEnd = msgStart + msg.length() - 1;
            
            if (isSection(spoilerBit, msgStart, msgEnd)) {
                spoilerWord.add(msg);
            } else {
                openWord.add(msg);
            }
            
            // 아 여기서 한번 채점 실패함
            // 공백만 생각해서 +1 했었는데, 생각해보니 msgEnd까지가 그 단어니까 +2 해야지 다음 단어 
            msgStart = msgEnd + 2; 
        }

        // 결과 종합
        int result = 0;
        while (!spoilerWord.isEmpty()) {
            String word = spoilerWord.remove();
            
            if (openWord.contains(word)) continue;
            
            openWord.add(word);
            result++;
        }
        
        return result;
    }
}

/*
단어: 
- 공백으로 구분
- 일부만 스포_방지_구간 인 경우 해당 단어도 스포_방지_단어로 간주
- 하나의 스포방지구간에 여러 단어가 포함될 수 있음

중요한 단어:
- 스포 방지 단어
- 스포 방지 구간이 아닌 구간에 등장한 적 없음
- 이전에 공개된 단어와 중복 X

set() clear() get()

*/