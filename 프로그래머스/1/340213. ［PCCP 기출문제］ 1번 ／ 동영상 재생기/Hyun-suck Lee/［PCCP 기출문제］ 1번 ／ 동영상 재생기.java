class Solution {
    class Time {
        private int min;
        private int sec;
        
        Time(String time) {
            String[] split = time.split(":");
            min = Integer.parseInt(split[0]);
            sec = Integer.parseInt(split[1]);
        }
        
        public void prev() {
            sec -= 10;
            if (sec < 0) {
                min--;
                sec += 60;
            }
            
            // 시간 최소값 00:00
            if (min < 0) {
                min = 0;
                sec = 0;
            }
        }
        
        // 시간으로 넘어가는 반례 있으면 여기 확인필요 (mm:ss 형식이라 일단 깊게 안씀)
        public void next() {
            sec += 10;
            if (sec >= 60) {
                min++;
                sec -= 60;
            }
        }
        
        // 특정 구간에 속하는지
        public boolean isInSection(Time start, Time end) {
            int now = this.toSecond();
            
            return start.toSecond() <= now && now <= end.toSecond();
        }
        
        // 특정 시간 넘었는지
        public boolean isOver(Time time) {
            return this.toSecond() > time.toSecond();
        }
        
        public void changTime(Time time) {
            this.min = time.min;
            this.sec = time.sec;
        }
        
        public int toSecond() {
            return min * 60 + sec;
        }
        
        public String toString() {
            String min = this.min < 10 ? "0" + this.min : this.min + "",
                   sec = this.sec < 10 ? "0" + this.sec : this.sec + "";
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