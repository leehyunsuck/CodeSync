#include <string>
#include <vector>

using namespace std;

int calc_accept_time(int time) {
    time += 10;
    if(time % 100 >= 60) {
        time += 40;
    }
    return time;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int check=0;check<schedules.size();check++) {
        int count = 0;
        for(int day=0;day<7;day++) {
            if((startday + day) % 7 > 0 && (startday + day) % 7 < 6) {            
                int accept_time = calc_accept_time(schedules[check]);
                int real_time = timelogs[check][day];
                
                if(real_time <= accept_time) 
                    count++;
                else
                    break;
            }
        }
        
        if(count == 5)
            answer += 1;
    }
    
    return answer;
}

/*
출근 희망 시간 + 10분
모든 시각 = 시 * 100 + 분

* 토, 일은 제외
n = 1(월요일) 2(화) 3(수) 4(목) 5(금) 6, 7(토, 일)

schedules = 출근 희망 시각 + 10
timelogs = 실제 출근 시간
startday 6, 7은 제외 7 넘어가면 다시 1부터 startday 

* c++ 에서 배열, 벡터 등의 크기는 vec.size() 임

- 실패했던 코드 / 원인 분석
if((startday + day) % 7 != 0 || (startday + day) % 7 != 6)
 -> 아, 일요일일 때 0 인데 OR 연산자로 처리해서 결국에는 주말도 포함되서 계산됨
*/