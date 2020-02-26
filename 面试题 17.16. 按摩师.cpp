
一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-masseuse-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
斐波那契
class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int pprev = nums[0];
        if(nums.size() == 1) return pprev;
        int prev = max(nums[1], pprev);
        for(int i = 2; i < nums.size(); ++i){
            int curr = max(prev, pprev+nums[i]);
            pprev = prev;
            prev = curr;
        }
        return prev;
    }
};
