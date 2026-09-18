import java.util.*;

class Solution {
    public String solution(String new_id) {
        StringBuilder builder = new StringBuilder();
        
        for (char c : new_id.toLowerCase().toCharArray()) { // 1단계 (모두 소문자로)
            if (!isPassChar(c))                continue;    // 2단계 (허용 문제 외 제거)
            if (this.isDotOverLap(builder, c)) continue;    // 3단계 .. 불가
            builder.append(c);
        }
        
        this.deleteDotToFE(builder);   // 4단계 (첫과 끝 . 제거)
        
        if (builder.length() == 0) {   // 5단계 (비어있는 경우 a 삽입)
            builder.append('a');
        }
        
        if (builder.length() >= 16) {  // 6-1단계 (최대 15자로)
            builder.delete(15, builder.length());
        }
        
        this.deleteDotToFE(builder);   // 6-2단계 -> 4단계
        
        while (builder.length() < 3) { // 7단계 (최소 3자로)
            builder.append(builder.charAt(builder.length() - 1));
        }

        return builder.toString();
    }
    
    public boolean isPassChar(char target) {
        int c = (int) target;
        
        if (97 <= c && c <= 122)           return true; // 알파엣 소문자
        if (48 <= c && c <= 57 )           return true; // 숫자
        if (c == 45 || c == 95 || c == 46) return true; // - _ .   
        
        return false;
    }
    
    public boolean isDotOverLap(StringBuilder builder, char c) {
        return builder.length() > 0 && this.isDot(c) && this.isDot(builder.charAt(builder.length() - 1));
    }

    public void deleteDotToFE(StringBuilder builder) {
        while (builder.length() > 0 && this.isDot(builder.charAt(0))) {
            builder.deleteCharAt(0);
        }
        while (builder.length() > 0 && this.isDot(builder.charAt(builder.length() - 1))) {
            builder.deleteCharAt(builder.length() - 1);
        }
    }

    public boolean isDot(char target) {
        return (int) target == 46;
    }

    public void testPrintChar() {
        System.out.printf("a: %d, z: %d, 0: %d, 9: %d, -: %d, _: %d, .: %d\n",
                         (int)'a', (int)'z', (int)'0', (int)'9', (int)'-', (int)'_', (int)'.'
                         );
    }
}

/*
단계:
1. 모든 문자 소문자로 변경
2. 허용 문자 외 제거
3. .. -> .
4. 처음과 끝의 . 제거
5. 빈 문자열이면 a 대입
6-1. 16자 이상 전부 제거
6-2. 4단계
7. 2자 이하인 경우 마지막 문자 반복해서 최소 길이 3일 때 까지 이어붙임
*/