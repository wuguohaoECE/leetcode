//wrong way
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        size_t size1 = matrix.size();
        size_t size2;
        if(size1 != 0) size2 = matrix[0].size();
        if(size1 == 0 || size2 == 0) return ans;
        vector<vector<int>> Pacific(size1, vector<int>(size2, 0)), Atlantic(size1, vector<int>(size2, 0));
        for(int i = 0; i < size1; ++i){
            Pacific[i][0] = 1;
            Atlantic[i][size2-1] = 1;
        }
        for(int i = 0; i < size2; ++i){
            Pacific[0][i] = 1;
            Atlantic[size1-1][i] = 1;
        }
        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                FindPacific(Pacific, matrix, i, j);
                FindPacific(Atlantic, matrix, i, j);
            }
        }
        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                if(Pacific[i][j] == 1 && Atlantic[i][j] == 1) ans.push_back({i,j});
            }
        }
        return ans;

    }
    bool FindPacific(vector<vector<int>>& pacific,vector<vector<int>>& matrix, int i, int j){
        if(pacific[i][j] != 0) return pacific[i][j]==1 ? true : false;
        size_t size1 = pacific.size();
        size_t size2 = pacific[0].size();
        bool IsConnected = false;
        if(i>0 && matrix[i-1][j] < matrix[i][j]){
            IsConnected = FindPacific(pacific, matrix, i-1, j);
        }
        if(!IsConnected && i<size1-1 && matrix[i+1][j] < matrix[i][j]){
            IsConnected = FindPacific(pacific, matrix, i+1, j);
        }
        if(!IsConnected && j>0 && matrix[i][j-1] < matrix[i][j]){
            IsConnected = FindPacific(pacific, matrix, i, j-1);
        }
        if(!IsConnected && j<size2-1 && matrix[i][j+1] < matrix[i][j]){
            IsConnected = FindPacific(pacific, matrix, i, j+1);
        }
        pacific[i][j] = IsConnected ? 1 : -1;
        return IsConnected;
    }
};
