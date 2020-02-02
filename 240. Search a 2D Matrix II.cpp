class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        if(i == -1) return false;
        int j = 0; int size = matrix[0].size();
        while(i >= 0 && j < size){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] < target){
                ++j;
            }
            else{
                --i;
            }
        }
        return false;
    }
};
