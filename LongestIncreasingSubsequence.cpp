//时间O(n2) 空间O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 1) return 1;
        if(size == 0) return 0;
        vector<int> records(size, 0);
        records[0] = 1;
        for(int i = 1; i < size; ++i){
            int curr = 1;
            for(int j = 0; j < i; ++j){
                if(nums[size-1-j] > nums[size-1-i] && curr <= records[j]) curr = records[j]+1;  
            }
            records[i] = curr;
        }
        int MaxNum = records[0];
        for(int i = 1; i < size; ++i){
            if(records[i] > MaxNum) MaxNum = records[i];
        }
        return MaxNum;
    }
};
