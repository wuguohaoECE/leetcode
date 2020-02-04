class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        if(nums.back() >= nums.front()) return BinarySerach(nums, 0, nums.size()-1, target);
        int BreakPoint = FindMinPoint(nums, 0, nums.size() - 1);
        cout << BreakPoint << endl;
        if(target < nums[0]) return BinarySerach(nums, BreakPoint+1, nums.size()-1, target);
        return BinarySerach(nums, 0, BreakPoint, target);
    }
    int FindMinPoint(vector<int>& nums, int begin, int end){//找分界点，就是最大的那个点
        int mid = (begin+end)/2;
        if(mid > begin && nums[mid] < nums[begin] && nums[mid-1] >= nums[begin]) return mid-1;
        if(mid < end && nums[mid] > nums[end] && nums[mid+1] <= nums[end]) return mid;
        if(nums[mid] > nums[begin]) return FindMinPoint(nums, mid+1, end);
        return FindMinPoint(nums, begin, mid-1);
    }
    int BinarySerach(vector<int>& nums, int begin, int end, int target){
        int mid = (begin+end)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target && mid < end) return BinarySerach(nums, mid+1, end, target);
        if(nums[mid] > target && mid > begin) return BinarySerach(nums, begin, mid-1, target);
        return -1;
    }
};
