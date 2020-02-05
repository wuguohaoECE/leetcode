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
