// 이번에는 객체로 풀어보기

class Solution {
    // bandage [ [최대_지속_시간, 초당_회복량, 추가_회복량], ... ]
    // attacks [ [time, damage], ... ]
    public int solution(int[] bandage, int health, int[][] attacks) {
        Hero hero = new Hero(bandage, health);
    
        int maxRound  = attacks[attacks.length - 1][0],
            attackIdx = 0;
        for (int round = 1; round <= maxRound; round++) {
            // 공격 라운드 아님
            if (round != attacks[attackIdx][0]) {
                hero.heal();
                continue;
            }
            // 공격 라운드 맞음
            hero.beAttacked(attacks[attackIdx][1]);
            attackIdx++;
            
            if (hero.isDie()) break;
        }
        
        return hero.getHp();
    }
}

class Hero {
    private int maxHp;
    private int hp;
    private int healTime;       // 현재 힐 지속시간
    private int healAmount;         
    private int rewardTime;     // 추가 회복하는 회복 지속시간
    private int rewardAmount;
    
    public Hero(int[] bandage, int health) {
        this.hp             = health;
        this.maxHp          = health;
        this.healTime       = 0;
        this.rewardTime     = bandage[0];
        this.healAmount     = bandage[1];
        this.rewardAmount   = bandage[2];
    }
    
    public void heal() {
        int healHp   = this.hp + healAmount,
            healTime = this.healTime + 1;
        
        if (healTime == this.rewardTime) {
            healHp += rewardAmount;
            healTime = 0;
        }
        
        this.healTime = healTime;
        this.hp = healHp <= maxHp ? healHp : maxHp;
    }
    
    public void beAttacked(int damage) {
        this.hp -= damage;
        this.healTime = 0;
        
        if (this.hp <= 0) {
            this.hp = -1;
        }
    }
    
    public boolean isDie() {
        return this.hp == -1;
    }
    
    public int getHp() {
        return this.hp;
    }
}

/*
- t(초) 동안 붕대 감으면서 1초마다 x(HP) 회복
- t(초) 연속 회복시 y(HP) 추가 회복
 
- 도중에 공격 당하면 취소
- 공격 당하는 순간에는 회복 불가

- 기술이 끝나거나 공격 당하면 바로 다시 사용

return HP > 0 ? HP : -1;

*/