//dfs+并查集。 空间O(n), 时间O(n)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 1 || board[0].size() <= 1) return;
        int size1 = board.size(); int size2 = board[0].size();
        vector<vector<bool>> records(size1, vector<bool>(size2, true));
        for(int j = 0; j < size2; ++j){
            if(board[0][j] == 'O') bfs(board, records, 0, j);
            if(board[size1-1][j] == 'O') bfs(board, records, size1-1, j);
        }
        for(int i = 1; i < size1-1; ++i){
            if(board[i][0] == 'O') bfs(board, records, i, 0);
            if(board[i][size2-1] == 'O') bfs(board, records, i, size2-1);
        }
        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                if(records[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& records, int i, int j){
        //cout << i << " " << j << endl;
        records[i][j] = false;
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int size1 = board.size(); int size2 = board[0].size();
        for(int q = 0; q < 4; ++q){
            int newi = i+dir[q][0];
            int newj = j+dir[q][1];
            if(IsValid(newi, newj, size1, size2) && board[newi][newj] == 'O' && records[newi][newj]){
                //cout << newi << " enter " << newj << endl;
                bfs(board, records, newi, newj);
            }
        }
        //cout << "end" << endl;
    }
    bool IsValid(int i, int j, int size1, int size2){
        return i>=0 && j>=0 && i<size1 && j<size2;
    }
    
};
