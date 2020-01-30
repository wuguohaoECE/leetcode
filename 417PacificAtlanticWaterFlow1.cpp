// queue对应DFS
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        size_t size1 = matrix.size();
        size_t size2;
        if(size1 != 0) size2 = matrix[0].size();
        if(size1 == 0 || size2 == 0) return ans;
        vector<vector<int>> Ocean(size1, vector<int>(size2, 0));
        queue<pair<int, int >> queue;
        for(int i = 0; i < size1; ++i){
            Ocean[i][0] |= 1;
            queue.push({i,0});
            Ocean[i][size2-1] |= 2;
            queue.push({i,size2-1});
        }
        for(int i = 0; i < size2; ++i){
            Ocean[0][i] |= 1;
            queue.push({0,i});
            Ocean[size1-1][i] |= 2;
            queue.push({size1-1,i});
        }
        int dir[4][2] {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        while(!queue.empty()){
            pair<int, int> curr = queue.front();
            queue.pop();
            for(int q = 0; q < 4; ++q){
                int i = curr.first+dir[q][0], j = curr.second+dir[q][1];
                if(IsValid(i,j,size1,size2) && matrix[i][j] >= matrix[curr.first][curr.second] && Ocean[i][j] != Ocean[curr.first][curr.second]){
                    Ocean[i][j] |= Ocean[curr.first][curr.second];
                    queue.push({i,j});
                }
            }
        }
        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                if(Ocean[i][j] == 3) ans.push_back({i,j});
            }
        }
        return ans;

    }
    bool IsValid(int i, int j, int size1, int size2){
        return !(i==-1 || j==-1 || i==size1 || j==size2);
    }
   
};
