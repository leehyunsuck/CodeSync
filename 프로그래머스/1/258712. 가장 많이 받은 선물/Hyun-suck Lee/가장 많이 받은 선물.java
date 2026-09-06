import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        // 사람 : {에게 준 사람, 몇 개}
        Map<String, Map<String, Integer>> giftForMe = new HashMap<>();
        // 사람 : 선물 지수
        Map<String, Integer> giftScore = new HashMap<>();
        
        for (String userA : friends) {
            Map<String, Integer> giftCount = new HashMap<>();
            
            for (String userB : friends) {
                if (userA.equals(userB)) continue;
                giftCount.put(userB, 0);
            }
            
            giftForMe.put(userA, giftCount);
            giftScore.put(userA, 0);
        }
        
        for (String gift : gifts) {
            String[] whoToWhom = gift.split(" ");
            String who  = whoToWhom[0],
                   whom = whoToWhom[1];
            
            giftScore.merge(who, 1, Integer::sum);
            giftForMe.get(whom).merge(who, 1, Integer::sum);    // 준 개수 먼저 종합
        }
        
        // giftScore 최종 계산 (받은 개수 빼야 함)
        for (String user : friends) {
            int getGiftCount = 0;
            for (int count : giftForMe.get(user).values()) {
                getGiftCount -= count;
            }
            
            giftScore.merge(user, getGiftCount, Integer::sum);
        }
        
        // 결과 종합
        int result = 0;
        for (String userA : friends) {
            int aWillGetGift = 0;
            
            int aScore = giftScore.get(userA);
            
            for (String userB : friends) {
                if (userA.equals(userB)) continue;
                
                int aForB = giftForMe.get(userB).get(userA),
                    bForA = giftForMe.get(userA).get(userB);
                
                if (aForB < bForA) continue;            // A가 준 개수가 더 적음
                if (aForB == bForA) {
                    int bScore = giftScore.get(userB);  
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