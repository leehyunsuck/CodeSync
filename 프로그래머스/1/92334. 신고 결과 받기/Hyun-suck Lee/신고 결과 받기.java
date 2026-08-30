import java.util.*;

class Solution {
    public int[] solution(String[] idList, String[] report, int k) {
        // 누구를 : {누가_신고, ...}
        Map<String, Set<String>> reportUserMap = new HashMap<>();
        // 누가 : 받을_메일_개수
        Map<String, Integer> userMailCountMap = new HashMap<>();
        
        for (String id : idList) {
            reportUserMap.put(id, new HashSet<>());
            userMailCountMap.put(id, 0);
        }
        
        // report 데이터 가공
        for (String log : report) {
            // [신고자, 대상]
            String[] reportLog = log.split(" ");
            String who  = reportLog[0],
                   whom = reportLog[1];
            
            reportUserMap.get(whom).add(who);
        }
  
        // reportUserMap 데이터 가공
        for (Map.Entry<String, Set<String>> entry : reportUserMap.entrySet()) {
            if (entry.getValue().size() < k) continue;
            
            for (String user : entry.getValue()) {
                userMailCountMap.merge(user, 1, Integer::sum);
            }
        }
        
        // int[] 로 결과값 생성
        int[] result = new int[idList.length];
        for (int idx = 0; idx < result.length; idx++) {
            result[idx] = userMailCountMap.get(idList[idx]);
        }
        
        return result;
    }
}

/*
기능: 신고 처리 결과 안내

규칙:
- User는 한 번에 한 명의 유저만 신고 가능 
    - 다른 유저 신고 가능
    - 제한 횟수 없음
    - 동일 인물에 대한 신고는 1회 처리
- k번 이상 신고된 유저는 정지
    - 이 사람을 신고한 유저들에게 안내

return id_list 순서에 맞게 각 유저가 받는 처리 결과 메일 개수
*/