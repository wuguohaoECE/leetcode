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

//时间O(nlog(n)) 空间O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> IncreasedList;
        IncreasedList.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > IncreasedList.back()){
                IncreasedList.push_back(nums[i]);
            }
            else{
                FindAndReplace(nums[i], IncreasedList, 0, IncreasedList.size()-1);
            }
        }
        return IncreasedList.size();
    }
    // 找到IncreasedList这个递增数列里面第一个大于num的数，并将其替换成num
    //原理是increasedList是当前最长子序列，它的长度是最长子序列的长度。递增子序列最核心的信息是有两个，一是长度，二是最大值。这两个信息是对的情况下，
    //其他信息其实怎么变化都没有关系。因此，用num替换子序列中第一个大于它的数既不会影响原序列信息，又可以通过逐步替换旧的序列，从而可能形成更长的序列。
    void FindAndReplace(int num, vector<int>& IncreasedList, int start, int end){
        if(IncreasedList[start] >= num) IncreasedList[start] = num;
        else if(end - start == 1) IncreasedList[end] = num;
        else if (IncreasedList[(start+end)/2] > num) FindAndReplace(num, IncreasedList, start, (start+end)/2);
        else FindAndReplace(num, IncreasedList, (start+end)/2, end);
    }
};
