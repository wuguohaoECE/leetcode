//回溯法
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool FirstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if(p.size() >= 2 && p[1] == '*'){
            //两种情况，一是*匹配0个，这样相当于p的前两个元素都作废
            //二是匹配多个，这样p还能继续使用，而s的第一个元素则视为成功匹配
            return isMatch(s, p.substr(2)) || (FirstMatch && isMatch(s.substr(1), p));
        }
        return FirstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

//dp法，用了array存了中间变量
class Solution {
public:
    bool isMatch(string s,string p){
	    bool dp[s.length()+1][p.length()+1];  
	    dp[0][0]=true; //dp[i][j]表示s有i个，p有j个字符下，是否是match的。s和p都没有字符显然是对的
        //首先预设s为空时的情况,这里要注意p[j]和dp[0][j]的j涵义不一样，p[j]是第j+1个，而dp[0][j]是第j个
        for(int j = 0; j < p.length(); ++j){
            if(p[j] == '*'){
                //当p的j+1个字符是"*"时，因为s是空，只能匹配0个，也就是p的第j+1个和j个作废
                //此时是否match取决于作废后的p是否和空的s匹配
                dp[0][j+1] = dp[0][j-1];
            }
            else{
                dp[0][j+1] = false;
            }
        }
        //接着预设p为空的情况，显然的，若此时s不为空，那么一定不会match
        for(int i = 0; i < s.length(); ++i){
            dp[i+1][0] = false;
        }

        //这里是算法开始部分，可能有的一个疑问是为什么i和j还是从0开始。这是因为上面两个for循环的0是dp的0，也就是没有元素，这里的0是p和s的0，也就是有一个元素。
        for(int i = 0; i < s.length(); ++i){
            for(int j = 0; j < p.length(); ++j){
                if(p[j] == s[i] || p[j] == '.'){
                    //这种情况很好理解，p的第j+1个字符和s的第i+1个字符匹配了，那么整个字符串是否匹配
                    //取决于去掉这一位后是否匹配
                    dp[i+1][j+1] = dp[i][j];
                }
                //如果s的第i+1个字符和p的第j+1个字符不匹配的话，那这两段要想还匹配，只能寄希望于p的j+1个字符是"*"了
                else if(j > 0 && p[j] == '*'){
                    if(p[j-1] == s[i] || p[j-1] == '.'){
                        //此时，p的第j个字符是和s的第i+1个字符匹配的，那么有两个可能，第一是*通配多个p[j-1]，此时s的第i+1个字符相当于作废了。 第二个可能是*通配0个字符，此时第p的第j+1和第j个字符作废
                        dp[i+1][j+1] = (dp[i][j+1] || dp[i+1][j-1]);
                    }
                    else{
                        //此时，p的第j个字符是和s的第i+1个字符不匹配，那么只能将p的第j+1和第j个字符作废
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
                }
                else{
                    dp[i+1][j+1] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
