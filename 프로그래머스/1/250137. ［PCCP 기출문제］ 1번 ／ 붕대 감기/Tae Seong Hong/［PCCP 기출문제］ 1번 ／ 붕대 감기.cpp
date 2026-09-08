#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int last_time = attacks[attacks.size() - 1][0];
    int time = 1;
    int max_health = health;
    int heal_time = 0;
    int mob_count = 0;
    
    while(time <= last_time) {
        int attack_time = attacks[mob_count][0];
        int damage = attacks[mob_count][1];
        
        if(time == attack_time) {
            health -= damage;
            heal_time = 0;
            mob_count++;
            if(health <= 0) {
                answer = -1;
                break;
            }
            answer = health;
        } else {
            heal_time++;
            if(heal_time == bandage[0]) {
                health += bandage[2];
                heal_time = 0;
            }
            health += bandage[1];
            if(health >= max_health)
                health = max_health;
        }
        time++;
    }
    
    return answer;
}

/*
t초 동안 1초/x만큼 -> t = 4, x = 4 -> 16
t초 연속 성공 -> y만큼 추가 회복
최대 체력 이상은 회복 불가능
공격 당하면 취소
공격은 정해진 피해량 만큼 체력이 줄고, 0이하면 사망
죽으면 -1을 리턴

bandage = [시전 시간 t, 초당 회복량 x, 추가 회복량 y]
health = 최대 체력
attacks = [[공격 시간 t, 피해량 x]]

끝나는 시간은 몬스터의 마지막 공격

* 풀이
 

*/