class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) throw exception();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] +nums[2];
        for(int i = 0; i < nums.size()-2; ++i){
            int L = i+1, R = nums.size() - 1;
            while(L < R){
                int curr = nums[i] + nums[L] +nums[R];
                if(dist(curr, target) < dist(closest, target)){
                    closest = curr;
                }
                if(curr < target){
                    ++L;
                }
                else{
                    --R;
                }
            }
            if(closest == target) return target;
        }
        return closest;
    }
    int dist(int i, int j){
        return abs(i-j);
    }
};
