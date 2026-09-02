#include <string>
#include <vector>

using namespace std;

int calc_time(int time, int command_time) {
    
    time += command_time;
    if(time % 100 >= 60) {
        time += 40 * (command_time / 10);
    }
    return time;
}

int check_opening(int time, int open_start, int open_end) {
   if(time >= open_start && time <= open_end)
       return open_end;
    else
        return time;
}

int check_time(int time, int video_time) {
    if(time < 0)
        return 0;
    else if(time > video_time)
        return video_time;
    else
        return time;
        
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int pos_calc = stoi(pos.substr(0, 2)) * 100 + stoi(pos.substr(3, 2));
    int op_end_calc = stoi(op_end.substr(0, 2)) * 100 + stoi(op_end.substr(3, 2));
    int op_start_calc = stoi(op_start.substr(0, 2)) * 100 + stoi(op_start.substr(3, 2));
    int video_len_calc = stoi(video_len.substr(0, 2)) * 100 + stoi(video_len.substr(3, 2));
    
    for(string command : commands) {
        pos_calc = check_opening(pos_calc, op_start_calc, op_end_calc);
        if(command == "next")
            pos_calc = calc_time(pos_calc, 10);
        else
            pos_calc = calc_time(pos_calc, -10);
        pos_calc = check_time(pos_calc, video_len_calc);
    }
    
    pos_calc = check_opening(pos_calc, op_start_calc, op_end_calc);
    
    // 뭔가 더 간결하게 만들 수 있는 방법이 있을 거 같은데
    // 내일 신고 결과 수정하면서 얘도 형식 지정을 할 수 있는지 찾아볼 예정
    if(pos_calc / 100 < 10)
        answer += "0";
    answer += to_string(pos_calc / 100) + ":";
    
    if(pos_calc % 100 < 10)
        answer += "0";
    answer += to_string(pos_calc % 100);
    
    
    return answer;
}

/*
동작 : 10초 전 / 10초 후 / 오프닝 건너뛰기
10초 전 : prev 명령 입력 -> 현재 위치에서 10초 전 이동 -> 10초 미만이면 처음 위치
10초 후 : next 명령 입력 -> 현재 위치에서 10초 후 이동 -> 남은 시간이 10초 미만이면 마지막  위치
오프닝 건너뛰기 : op_start <= 현재 재생 위치 <= op_end 인 경우

pos = 현재 위치

* 문자열 슬라이싱 - string 헤더 필요
 string.substr(start, length);

* 형변환
 stoi - string to int
 to_string - int to string
        
*/