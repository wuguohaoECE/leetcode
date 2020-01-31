class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        size_t size = nums.size();
        int i = 0;
        while(i < size && !map.count(nums[i])){
            map[target - nums[i]] = i;
            ++i;
        }
        if(i == size) {
            return vector<int>();
        }
        return vector<int>({map[nums[i]], i});
    }
};
