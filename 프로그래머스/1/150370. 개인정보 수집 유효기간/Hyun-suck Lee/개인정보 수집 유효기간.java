import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        Map<String, Integer> termMap = new HashMap<>();
        for (String term : terms) {
            String[] info = term.split(" "); // {타입, 몇개월}
            termMap.put(info[0], Integer.parseInt(info[1]));
        }
        
        Date now = new Date(today);
        
        List<Integer> temp = new ArrayList<>();
        for (int idx = 0; idx < privacies.length; idx++) {
            String[] info = privacies[idx].split(" "); // {가입날짜, 타입}
            
            Date user = new Date(info[0]);
            user.upMonth(termMap.get(info[1]));
            user.downDay(1); // user는 만료일이니까 -1
            
            // user(만료일)이 현재_날짜(now)보다 더 크거나 같으면 아직 안지남 -> 1, 0
            if (user.isMoreBig(now) != -1) continue;
            temp.add(idx + 1);
        }
        
        int[] result = new int[temp.size()];
        for (int idx = 0; idx < result.length; idx++) {
            result[idx] = temp.get(idx);
        }
        
        return result;
    }
}

class Date {
    private int year;
    private int month;
    private int day;
    
    Date(String date) {
        String[] info = date.split("\\.");
        this.year     = Integer.parseInt(info[0]);
        this.month    = Integer.parseInt(info[1]);
        this.day      = Integer.parseInt(info[2]);
        this.optimeze();
    }
    
    public void upMonth(int month) {
        this.month += month;
        this.optimeze();
    }
    
    public void downDay(int day) {
        this.day -= day;
        this.optimeze();
    }
    
    public int isMoreBig(Date tg) {
        if (this.year  != tg.year ) return this.year  > tg.year  ? 1 : -1;
        if (this.month != tg.month) return this.month > tg.month ? 1 : -1;
        if (this.day   != tg.day  ) return this.day   > tg.day   ? 1 : -1;
        return 0;
    }
    
    private void optimeze() {
        if (this.day > 28) {
            this.month += (this.day - 1) / 28;
            this.day    = (this.day - 1) % 28 + 1;
        }
        if (this.day <= 0) {
            this.month -= 1;
            this.day   += 28;
        }
        
        if (this.month > 12) {
            this.year += (this.month - 1) / 12;
            this.month = (this.month - 1) % 12 + 1;
        }
        if (this.month <= 0) {
            this.year  -= 1;
            this.month += 12;
        }
    }
}