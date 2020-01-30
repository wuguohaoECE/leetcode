//BFS效率不高
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        size_t size1 = grid.size();
        size_t size2;
        if(size1 != 0) size2 = grid[0].size();
        if(size1 == 0 || size2 == 0) return 0;
        queue<pair<int, int >> queue;
        int perimeter = 0;
        bool flag = false;
        for(int i = 0; i < size1*size2; ++i){
            if(grid[i/size2][i%size2] == 1){
                queue.push({i/size2,i%size2});
                grid[i/size2][i%size2] = 2;
                perimeter = 4;
                break;
            }
        }
        int dir[4][2] {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        while(!queue.empty()){
            pair<int, int> curr = queue.front();
            queue.pop();
            for(int q = 0; q < 4; ++q){
                int i = curr.first+dir[q][0], j = curr.second+dir[q][1]; 
                if(IsValid(i,j,size1,size2)){
                    if(grid[i][j] == 1){
                        queue.push({i,j});
                        grid[i][j] = 2;
                        perimeter += 3;
                    }
                    else if(grid[i][j] == 2){
                        perimeter -= 1;
                    }
                }
            }
        }
        return perimeter;
    }
    bool IsValid(int i, int j, int size1, int size2){
        return !(i==-1 || j==-1 || i==size1 || j==size2);
    }
};

//简单解法666
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        size_t size1 = grid.size();
        size_t size2;
        if(size1 != 0) size2 = grid[0].size();
        if(size1 == 0 || size2 == 0) return 0;
        int Perimeter = 0;
        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                if(grid[i][j] == 1){
                    if(i == 0 || grid[i-1][j] == 0) ++Perimeter;
                    if(i == size1-1 || grid[i+1][j] == 0) ++Perimeter;
                    if(j == 0 || grid[i][j-1] == 0) ++Perimeter;
                    if(j == size2-1 || grid[i][j+1] == 0) ++Perimeter;
                }
            }
        }
        return Perimeter;
    }
};
