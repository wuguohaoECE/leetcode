class Solution {
    private:
    unordered_map<char, string> map = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> output;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return vector<string>();
        dfs("", digits, 0);
        return output;
    }

    void dfs(string curr, string& digits, int i){
        if(i == digits.size()){
            output.push_back(curr);
        }
        string letters = map[digits[i]];
        for(int j = 0; j < letters.length(); ++j){
            dfs(curr + letters[j], digits, i+1);
        }
    }
};
