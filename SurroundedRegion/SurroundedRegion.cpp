class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 0) {
            return;
        }
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[i].size();++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'Y';
                }
            }
        }
        for(int i = 0;i < board.size();++i){
            if ( board[i][0] == 'Y') {
                fillMargin(board, i, 0);
            }
        }
        for(int i = 0;i < board.size();++i){
            if ( board[i][board[0].size()-1] == 'Y') {
                fillMargin(board, i, (int)board[0].size()-1);
            }
        }
        for(int j = 0;j < board[0].size();++j){
            if ( board[0][j] == 'Y') {
                fillMargin(board, 0, j);
            }
        }
        for(int j = 0;j < board[0].size();++j){
            if ( board[board.size()-1][j] == 'Y') {
                fillMargin(board, (int)board.size()-1, j);
            }
        }
        for(int i = 0;i < board.size();++i){
            for(int j = 0;j < board[i].size();++j){
                if(board[i][j] == 'Y'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    
    void fillMargin(vector<vector<char>>& board,int i,int j){
        if ( board[i][j] != 'Y') {
            return;
        }
        board[i][j] = 'O';
        if(i > 1){
            fillMargin(board, i-1, j);
        }
        if (i < board.size()-1) {
            fillMargin(board, i+1, j);
        }
        if (j > 1 ) {
            fillMargin(board, i, j-1);
        }
        if (i < board[0].size()-1) {
            fillMargin(board, i, j+1);
        }
        
    }
};