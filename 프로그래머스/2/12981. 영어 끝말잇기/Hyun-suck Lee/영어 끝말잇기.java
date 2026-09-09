// 예전에 공부했던 Trie 자료구조 써보기
import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] result = {0, 0};

        Trie trie = new Trie();
        
        char last = words[0].charAt(0);
        int sycle = 0;
        for (int idx = 0; idx < words.length; idx++) {
            String word = words[idx];
            
            if (idx % n == 0) {
                sycle++;
            } 
            
            // 규칙 안지킴
            if (word.charAt(0) != last || !trie.addWord(word) || word.length() == 1) {
                result[0] = idx % n + 1;
                result[1] = sycle;
                break;
            }
            
            last = words[idx].charAt(words[idx].length() - 1);
        }

        return result;
    }
}

class Trie {
    private Node root;
    
    public Trie() {
        this.root = new Node();
    }
    
    public boolean addWord(String word) {
        char[] spelling = word.toCharArray();
        
        Node node = this.root;
        for (int idx = 0; idx < spelling.length; idx++) {
            node = node.addNode(spelling[idx]);
        }
        
        if (node.getExist()) {
            return false;
        }
        node.setExist(true);
        
        return true;
    }
}

class Node {
    private Map<Character, Node> nodes;
    private boolean exist;
    
    public Node() {
        this.nodes = new HashMap<>();
        this.exist = false;
    }
    
    public Node addNode(char c) {
        if (!nodes.containsKey(c)) {
            this.nodes.put(c, new Node());
        }
        
        return this.nodes.get(c);
    }

    public void setExist(boolean exist) {
        this.exist = exist;
    }
    
    public boolean getExist() {
        return this.exist;
    }
}

/*

n(명)

끝말잇기
- 이미 말한 단어 안됨
- 한 글자 안됨
- 이전 단어 마지막 글자로 단어가 시작해야 함

return [먼저 탈락한 사람의 번호, 그 사람이 몇 번째 단어를 말했는지]

*/