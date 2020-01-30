//时间O(n) 空间O(1)
//根据题意，可以将nums看成是一个带有环的链表。通过快慢指针法可以找到环的起点，环起点对应的index（不是value）就是重复的那个数
//原理：首先长度为n，值范围是1到n-1。那么最大值是不超过长度的。在这种情况下，index的值指向下一个index，这样重复的那个数就一定会被遍历到。
//因为一，要想某个index（令它为i）不被遍历到，那么i这个值不能出现在别处，只能出现在index = i那里。
//而i这个值是重复的，那么就不可能只出现在index = i的那个位置。
//环起点对应的index就是重复的数的原因是：第一此遍历到value等于重复的那个数时，进去index = 重复的那个数 的那个位置，然后继续遍历，第二次到value为
//重复的那个数时，再次进去index = 重复的那个数。 这样就形成了一个环。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        int ptr = 0;
        while(ptr != slow){
            ptr = nums[ptr];
            slow = nums[slow];
        }
        return ptr;
    }
};
