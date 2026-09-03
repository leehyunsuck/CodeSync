import java.util.*;

class Solution {
    public int[][] solution(int[][] datas, String ext, int valExt, String sortBy) {
        // ext나 sortBy 등 명칭으로 인덱스 찾는 용도
        Map<String, Integer> fieldMap = new HashMap<>();
        
        String[] fields = {"code", "date", "maximum", "remain"};
        for (int idx = 0; idx < fields.length; idx++) {
            fieldMap.put(fields[idx], idx);
        }

        
        // 결과값 개수 모르니 List로 
        List<int[]> calc = new ArrayList<>();
        
        // data 에서 ext(field)값이 valExt보다 작은 데이터만 선택
        int baseExtIdx = fieldMap.get(ext);
        for (int[] data : datas) {
            if (data[baseExtIdx] >= valExt) continue;
            calc.add(data);
        }
        
        // sortBy 기준으로 오름차순
        int baseSortIdx = fieldMap.get(sortBy);
        calc.sort( (a1, a2) -> Integer.compare(a1[baseSortIdx], a2[baseSortIdx]) );
        
        int[][] result = new int[calc.size()][calc.get(0).length];
        for (int idx = 0; idx < calc.size(); idx++) {
            result[idx] = calc.get(idx);
        }
        
        return result;
    }
}