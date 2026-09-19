import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        return new KakaoPerTest()
                .setPerScores(survey, choices)
                .toString();
    }
}

class KakaoPerTest {
    private static final char[][] OPTIONS = new char[][] {
        {'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}
    };
    
    private Map<Character, Integer> perScore;
    
    public KakaoPerTest() {
        this.resetPerScore();
    }
    
    public KakaoPerTest setPerScores(String[] surveys, int[] choices) {
        for (int idx = 0; idx < surveys.length; idx++) {
            this.setPerScore(surveys[idx], choices[idx]);
        }
        return this;
    }
    
    public KakaoPerTest setPerScore(String survey, int choice) {
        char[] s = survey.toCharArray();
        
        if (choice < 4) {           // 1 2 3
            this.perScore.merge(s[0], 4 - choice, Integer::sum);
        } else if (choice > 4) {    // 5 6 7 
            this.perScore.merge(s[1], choice - 4, Integer::sum);
        }
        
        return this;
    }
        
    public String toString() {
        String str = "";
        
        for (char[] option : KakaoPerTest.OPTIONS) {
            str += this.perScore.get(option[0]) >= this.perScore.get(option[1]) 
                 ? option[0] : option[1];
        }
        
        return str;
    }
    
    private KakaoPerTest resetPerScore() {
        perScore = new HashMap<>();
        for (char[] option : KakaoPerTest.OPTIONS) {
            for (char o : option) {
                perScore.put(o, 0);
            }
        }
        return this;
    }
}