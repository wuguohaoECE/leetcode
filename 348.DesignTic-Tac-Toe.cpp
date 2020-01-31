class TicTacToe {
    private:
    vector<vector<int>> board;
    int n;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): board(vector<vector<int>>(n, vector<int>(n, 0))), n(n){
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0;
        for(; i<n; ++i){
            if(board[row][i] != player) break;
        }
        if(i == n) return player;
        i = 0;
        for(; i<n; ++i){
            if(board[i][col] != player) break;
        }
        if(i == n) return player;
        i = 0;
        if(col == row || col == (n-1-row)){
            for(; i<n; ++i){
                if(board[i][i] != player) break;
            }
            if(i == n) return player;
            i = 0;
            for(; i<n; ++i){
                if(board[i][n-1-i] != player) break;
            }
            if(i == n) return player;
        }
        return 0;
    }
};
