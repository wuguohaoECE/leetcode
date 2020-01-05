class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<size_t, size_t>> queue;
        set<pair<size_t, size_t>> used;
        size_t size1 = grid.size();
        if(size1 == 0){
            return 0;
        }
        size_t size2 = grid[0].size();
        int count = 0;
        for(size_t i = 0; i < size1; ++i){
            for(size_t j = 0; j < size2; ++j){
                pair<size_t, size_t> loc(i,j);
                if(used.count(loc)){
                    continue;
                }
                if(grid[i][j] == '0'){
                    continue;
                }
                queue.push(loc);
                used.insert(loc);
                while(!queue.empty()){
                    pair<size_t, size_t> curr = queue.front();
                    pair<size_t, size_t> temp(curr.first + 1, curr.second);
                    if(curr.first + 1 < size1 && !used.count(temp) && grid[curr.first+1][curr.second] == '1'){
                        queue.push(temp);
                        used.insert(temp);
                    }
                    temp = pair<size_t, size_t>(curr.first, curr.second + 1);
                    if(curr.second + 1 < size2 && !used.count(temp) && grid[curr.first][curr.second + 1] == '1'){
                        queue.push(temp);
                        used.insert(temp);
                    }
                    temp = pair<size_t, size_t>(curr.first-1, curr.second);
                    if(curr.first != 0 && !used.count(temp) && grid[curr.first-1][curr.second] == '1'){
                        queue.push(temp);
                        used.insert(temp);
                    }
                    temp = pair<size_t, size_t>(curr.first, curr.second - 1);
                    if(curr.second != 0 && !used.count(temp) && grid[curr.first][curr.second - 1] == '1'){
                        queue.push(temp);
                        used.insert(temp);
                    }
                    queue.pop();
                }
                ++count;
            }
        }
        return count;
    }
};
//这个方法采用set来记录搜索过的地方，不高效，下面用0，1法记录搜索过的地方
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<size_t, size_t>> queue;
        size_t size1 = grid.size();
        if(size1 == 0){
            return 0;
        }
        size_t size2 = grid[0].size();
        int count = 0;
        for(size_t i = 0; i < size1; ++i){
            for(size_t j = 0; j < size2; ++j){
                pair<size_t, size_t> loc(i,j);
                if(grid[i][j] == '0'){
                    continue;
                }
                queue.push(loc);
                grid[i][j] = '0';
                while(!queue.empty()){
                    pair<size_t, size_t> curr = queue.front();
                    pair<size_t, size_t> temp(curr.first + 1, curr.second);
                    if(curr.first + 1 < size1 && grid[curr.first+1][curr.second] == '1'){
                        queue.push(temp);
                        grid[curr.first+1][curr.second] = '0';
                    }
                    temp = pair<size_t, size_t>(curr.first, curr.second + 1);
                    if(curr.second + 1 < size2 && grid[curr.first][curr.second + 1] == '1'){
                        queue.push(temp);
                        grid[curr.first][curr.second+1] = '0';
                    }
                    temp = pair<size_t, size_t>(curr.first-1, curr.second);
                    if(curr.first != 0  && grid[curr.first-1][curr.second] == '1'){
                        queue.push(temp);
                        grid[curr.first-1][curr.second] = '0';
                    }
                    temp = pair<size_t, size_t>(curr.first, curr.second - 1);
                    if(curr.second != 0 && grid[curr.first][curr.second - 1] == '1'){
                        queue.push(temp);
                        grid[curr.first][curr.second-1] = '0';
                    }
                    queue.pop();
                }
                ++count;
            }
        }
        return count;
    }
};

//这个方法采用了dfs,而不是BFS.

class Solution {
public:
    void DFS(vector<vector<char>>& grid, size_t i, size_t j, size_t size1, size_t size2){
        grid[i][j] = '0';
        if(i+1 < size1 && grid[i+1][j] == '1') DFS(grid, i+1, j, size1, size2);
        if(j+1 < size2 && grid[i][j+1] == '1') DFS(grid, i, j+1, size1, size2);
        if(i != 0 && grid[i-1][j] == '1') DFS(grid, i-1, j, size1, size2);
        if(j != 0 && grid[i][j-1] == '1') DFS(grid, i, j-1, size1, size2);
    }
    int numIslands(vector<vector<char>>& grid) {
        size_t size1 = grid.size();
        if(size1 == 0){
            return 0;
        }
        size_t size2 = grid[0].size();
        int count = 0;
        for(size_t i = 0; i < size1; ++i){
            for(size_t j = 0; j < size2; ++j){
                if(grid[i][j] == '0'){
                    continue;
                }
                DFS(grid, i, j, size1, size2);
                ++count;
            }
        }
        return count;
    }
};
