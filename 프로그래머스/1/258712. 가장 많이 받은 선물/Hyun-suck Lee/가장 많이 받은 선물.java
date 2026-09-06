// 태성씨 코드 보고 초기화 로직 및 giftSocre 2차 로직 수정 
import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        // 사람 : {에게 준 사람, 몇 개}
        Map<String, Map<String, Integer>> giftForMe = new HashMap<>();
        // 사람 : 선물 지수
        Map<String, Integer> giftScore = new HashMap<>();
        
        for (String gift : gifts) {
            String[] whoToWhom = gift.split(" ");
            String who  = whoToWhom[0],
                   whom = whoToWhom[1];
            
            giftScore.merge(who, 1, Integer::sum);
            giftScore.merge(whom, -1, Integer::sum);    
            
            if (!giftForMe.containsKey(whom)) {
                giftForMe.put(whom, new HashMap<>());
            }
            giftForMe.get(whom).merge(who, 1, Integer::sum);
        }
        
        // 결과 종합
        int result = 0;
        for (String userA : friends) {
            int aWillGetGift = 0;
            
            int aScore = giftScore.getOrDefault(userA, 0);
            
            for (String userB : friends) {
                if (userA.equals(userB)) continue;
                
                int aForB = giftForMe
                        .getOrDefault(userB, Collections.emptyMap())
                        .getOrDefault(userA, 0),
                    bForA = giftForMe
                        .getOrDefault(userA, Collections.emptyMap())
                        .getOrDefault(userB, 0);
                
                if (aForB < bForA) continue;            // A가 준 개수가 더 적음
                if (aForB == bForA) {
                    int bScore = giftScore.getOrDefault(userB, 0);  
                    if (aScore <= bScore) continue;     // A 선물 지수가 더 작음
                }

                aWillGetGift++;
            }
            
            result = aWillGetGift > result ? aWillGetGift : result;
        }

        return result;
    }
}

/*
선물 기록을 토대로 다음 달 선물을 많이 받은 인원이 받는 개수 파악

서로 주고 받은 기록이 있다면?
- 더 많이 준 B가 A에게 줌

하나도 없거나 개수가 같다면?
- 선물 지수가 작은 B가 큰 A에게 줌

선물 지수도 동일하다면?
- 주고 받지 않음

선물 지수란?
- 준 선물의 개수 - 받은 선물의 개수

return 선물 받을 예측 수가 가장 높은 사람의 수
*/