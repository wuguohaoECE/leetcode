class Solution {
    vector<string> output;
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return output;
        helper("(", n-1, n-1, 1);
        return output;
    }
    void helper(string curr, int L, int R, int Rremain){
        if(L == 0 && R == 0){
            output.push_back(curr + ')');
            return;
        }
        if(L > 0) helper(curr+'(', L-1, R, Rremain+1);
        if(R > 0 && Rremain > 0) helper(curr+')', L, R-1, Rremain-1);
    }
};
