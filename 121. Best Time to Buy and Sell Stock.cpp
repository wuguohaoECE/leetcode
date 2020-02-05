//时间O(n) 空间O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max = 0;
        int LastProfit = 0;
        for(int i = 1; i < prices.size(); ++i){
            int CurrProfit = max(0, LastProfit+prices[i]-prices[i-1]);
            if(CurrProfit > Max) Max = CurrProfit;
            LastProfit = CurrProfit;
        }
        return Max;
    }
};
