class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int L = i+1, R = nums.size()-1;
            while(L < R){
                int curr = nums[i] + nums[L] + nums[R];
                if( curr == 0){
                    while(L < R && nums[L] == nums[L+1]) {
                        ++L;
                    }
                    while(L < R && nums[R-1] == nums[R]){
                        --R;
                    }
                    ans.push_back({nums[i], nums[L], nums[R]});
                    ++L; --R;
                    //break; 这里不能break，因为同时增加L和减少R时，可能会有更多的答案。
                }
                else if (curr < 0){
                    ++L;
                }
                else{
                    --R;
                }
            }
        }
        return ans;
    }
};
