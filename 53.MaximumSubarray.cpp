class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) throw exception();
        int LastMax = nums.back();
        int ans = LastMax;
        for(auto it = nums.rbegin()+1; it != nums.rend(); ++it){
            if(LastMax < 0){
                LastMax = *it;
            }
            else{
                LastMax += *it;
            }
            if(LastMax > ans) ans = LastMax;
        }
        return ans;
    }
};
