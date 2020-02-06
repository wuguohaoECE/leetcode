class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 0) return 0;
        int prepcost = cost[0], pprepcost = 0;
        for(int i = 1; i < cost.size(); ++i){
            int curr = min(pprepcost, prepcost) + cost[i];
            pprepcost = prepcost;
            prepcost = curr;
        }
        return min(pprepcost, prepcost);
    }
};
