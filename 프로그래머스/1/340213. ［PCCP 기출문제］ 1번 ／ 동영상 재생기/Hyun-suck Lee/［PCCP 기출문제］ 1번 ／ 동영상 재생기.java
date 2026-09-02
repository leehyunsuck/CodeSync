// 태성씨 풀이 보고 min, sec 로 분할한거 sec 만 사용하는걸로 변경
class Solution {
    class Time {
        private int sec;
        
        Time(String time) {
            String[] split = time.split(":");
            sec = Integer.parseInt(split[0]) * 60 + Integer.parseInt(split[1]);
        }
        
        public void prev() {
            sec -= 10;
            if (sec < 0) {
                sec = 0;
            }
        }
        
        public void next() {
            sec += 10;
        }
        
        // 특정 구간에 속하는지
        public boolean isInSection(Time start, Time end) {
            int now = this.getSec();
            
            return start.getSec() <= now && now <= end.getSec();
        }
        
        // 특정 시간 넘었는지
        public boolean isOver(Time time) {
            return this.getSec() > time.getSec();
        }
        
        public void changTime(Time time) {
            this.sec = time.getSec();
        }
        
        public int getSec() {
            return this.sec;
        }
        
        public String toString() {
            int iMin = this.sec / 60,
                iSec = this.sec % 60;
            
            String min = iMin < 10 ? "0" + iMin : iMin + "",
                   sec = iSec < 10 ? "0" + iSec : iSec + "";
            return min + ":" + sec;
        }
    }
    
    public String solution(String videoLen, String pos, String opStart, String opEnd, String[] commands) {
        Time skipStart = new Time(opStart),
             skipEnd   = new Time(opEnd),
             max       = new Time(videoLen),
             now       = new Time(pos);
        
        // 시작부터 skip 구간 (3번 예시로 알아차림)
        if (now.isInSection(skipStart, skipEnd)) {
            now.changTime(skipEnd);
        }

        for (String command : commands) {
            if (command.equals("prev")) {
                now.prev();
            } else if (command.equals("next")) {
                now.next();
            }
            
            // 이 문제에서 필요한 조건들임 
            if (now.isInSection(skipStart, skipEnd)) {
                now.changTime(skipEnd);
            }
            if (now.isOver(max)) {
                now.changTime(max);
            }
        }
        
        return now.toString();
    }
}

/*
command:
- prev : 10초 전으로 이동 (min 0 반영)
- next : 10초 후로 이동 (max 시간값 반영)

opStart <= time <= opEnd = 자동으로 오프닝 끝나는 위치로 스킵

시간 형식:
- "mm:ss"

return 동영상의 위치
*/