class Solution {
public:
    int rob(vector<int>& nums) {
        int MaxRob = 0, last1 = 0, last2 = 0, last3 = 0;
        for(int i = 0; i < nums.size(); ++i){
            int curr = nums[i] + max(last2, last3);
            if(curr > MaxRob) MaxRob = curr;
            last3 = last2;
            last2 = last1;
            last1 = curr;
        }
        return MaxRob;
    }
};
