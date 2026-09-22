#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> saves;
    int board_row = board.size() - 1;
    for(int move : moves) {
        int col = move - 1;
        
        if(board[board_row][col] == 0)
            continue;
        
        for(int row = 0;row <= board_row;row++) {
            if(board[row][col] != 0) {
                saves.push_back(board[row][col]);
                board[row][col] = 0;
                break;
            }
        }
        
        if(saves.size() > 1) {
            if(saves[saves.size() - 1] == saves[saves.size() - 2]) {
                saves.pop_back();
                saves.pop_back();
                answer += 2;
            }
        }
    }    
    return answer;
    
}

/*
moves = 크레인 이동 위치
board = 보드판

col = moves - 1

*/