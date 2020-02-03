//set+滑动窗口 时间O(2n) 空间 O(max(字符种类，字符串长度))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) return s.length();
        int L = 0, R = 1, size = s.length();
        int Longest = 0;
        unordered_set<int> set;
        set.insert(s[0]);
        while(R < size){
            if(set.count(s[R])){
                int curr = R-L;
                if(curr > Longest) Longest = curr;
                while(s[L] != s[R]){
                    set.erase(s[L]);
                    ++L;
                }
                ++L;
            }
            else{
                set.insert(s[R]);
            }
            ++R;
        }
        int curr = R-L;
        if(curr > Longest) Longest = curr;
        return Longest;
    }
};
//自制hashmap+滑动窗口, 时间O(n) 空间 O(字符总数)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2) return s.length();
        int size = s.length();
        int map[128] = {0};
        int ans = 0;
        int i = 0, j = 0;
        while(j < size){
            i = max(i, map[s[j]]);
            ans = max(ans, j-i+1);
            map[s[j]] = j+1; //方便下次更新i时直接跳到下一个；
            ++j;
        }
        return ans;
    }
};
