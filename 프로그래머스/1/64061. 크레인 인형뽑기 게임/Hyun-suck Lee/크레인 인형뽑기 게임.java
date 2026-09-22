import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        Game game = new Game(board);
        for (int move : moves) {
            game.moveToBasket(move - 1);
        }
        
        return game.getRemoveCount();
    }
}

class Game {
    private List<Deque<Integer>> board; // col 기준
    private Deque<Integer> basket;
    private int removeCount;
    
    public Game(int[][] board) {
        this.setBoard(board);
        this.basket = new ArrayDeque<>();
        this.removeCount = 0;
    }
    
    public void moveToBasket(int col) {
        Deque<Integer> target = board.get(col);
        if (target.size() == 0) return;
        
        if (target.size() > 0 && basket.peek() == target.peek()) {
            target.pop();
            basket.pop();
            removeCount += 2;
            return;
        }
        
        basket.push(target.pop());
    }
    
    public void setBoard(int[][] arrBoard) {
        this.board = new ArrayList<>();
        
        for (int i = 0; i < arrBoard[0].length; i++) {
            this.board.add(new ArrayDeque<>());
        }
        
        for (int row = arrBoard.length - 1; row >= 0; row--) {
            for (int col = 0; col < arrBoard[0].length; col++) {
                if (arrBoard[row][col] == 0) continue;
                this.board.get(col).push(arrBoard[row][col]);
            }
        }
    }
    
    public int getRemoveCount() {
        return this.removeCount;
    }
}

/*
- 게임맵: N * N 의 공간
- 바구니: 인형 최대 개수
- LIFO 구조임

- 바구니에 같은 모양 겹치면 제거됨

- 인형 없는 곳 잡아도 문제 X

return 겹쳐 제거된 인형 개수
*/