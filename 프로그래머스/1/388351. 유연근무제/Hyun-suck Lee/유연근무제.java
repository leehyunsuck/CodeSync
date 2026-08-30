class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int giftUserCount = 0;
        
        for (int user = 0; user < schedules.length; user++) {
            int maxTime = schedules[user] + 10,
                day  = startday;

            // 10분 더한 시간이 60분을 넘어가는 경우 값 조정
            if (maxTime % 100 >= 60) {
                maxTime += 40;
            }
            
            boolean canGetGift = true;

            for (int timelog : timelogs[user]) {
                if (day >= 8) {
                    day = 1;
                }
                if (day++ >= 6)         continue;
                if (timelog <= maxTime) continue;
                
                canGetGift = false;
                break;
            }
            
            if (canGetGift) {
                giftUserCount++;
            }
        }
        
        return giftUserCount;
    }
}

/*
- 설정한 출근 시간대에 출근해야함 [희망시각 + 10분 까지]
- 토요일(6), 일요일(7) 출근은 event 영향 X
- 모든 시각은 H * 100 + M 정수로 표현

return 한번도 늦지 않은 인원 수
*/