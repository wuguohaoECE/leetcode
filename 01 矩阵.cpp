//第一种方法采用了动态规划。
//令dist(i,j)为i,j这个点到最近0的距离。那么min(dist(i,1))就会等于在自己的距离以及周围四个点距离中取最小值。
//从左上往右下更新后，再从右下往左上更新。这样能保证每一个dist(i,j)是正确值，原因是：
//1，任意一个本身是1的点的距离，由距离其最近的左上方的点，和距离其最近的右下方的点决定（两者取较小值）
//2，第一个循环从左上往右下更新时，保证了dist(i,j)等于其距离左上的一个离其最近的点的距离。
//3，第二个循环从右下往左上更新时，保证了在原来基础上，同时比较右下方离其最近的点的距离。
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        if(rows == 0) return vector<vector<int>>();
        size_t cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX-1));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(matrix[i][j] == 0) dist[i][j] = 0;
                if(j > 0) dist[i][j] = min(dist[i][j], dist[i][j-1]+1);
                if(i > 0) dist[i][j] = min(dist[i][j], dist[i-1][j]+1);
            }
        }
        for(int i = rows-1; i >= 0; --i){
            for(int j = cols-1; j >= 0; --j){
                if(j < cols-1) dist[i][j] = min(dist[i][j], dist[i][j+1]+1);
                if(i < rows-1) dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
            }
        }
        return dist;
    }
};

//第二种方法采用了BFS法。
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        if(rows == 0) return vector<vector<int>>();
        size_t cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX-1));
        queue<pair<int,int>> queue;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(matrix[i][j] == 0) dist[i][j] = 0;
                queue.push({i,j});
            }
        }
        pair<int,int> curr;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!queue.empty()){
            curr = queue.front(); queue.pop();
            for(int i = 0; i < 4; ++i){
                int first = curr.first + dir[i][0]; int second = curr.second + dir[i][1];
                if(first > -1 && first < rows && second > -1 && second < cols &&
                  dist[first][second] > dist[curr.first][curr.second] + 1){
                    dist[first][second] = dist[curr.first][curr.second] + 1;
                    queue.push({first,second});
                }
            }
        }
        return dist;
    }
};
