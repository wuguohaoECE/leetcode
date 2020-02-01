class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, end = -1;
        for(int i = 0; i < s.size(); ++i){
            int L = i-1, R = i+1;
            while(L>=0 && R < s.size() && s[L] == s[R]){
                --L; ++R;
            }
            if(R-L-2 > end - begin){ //(R-1)-(L+1)
                end = R-1;
                begin = L+1;
            }

            if(i == s.size()-1 || s[i] != s[i+1]) continue;

            L = i-1, R = i+2;
            while(L>=0 && R < s.size() && s[L] == s[R]){
                --L; ++R;
            }
            if(R-L-2 > end - begin){ //(R-1)-(L+1)
                end = R-1;
                begin = L+1;
            }
        }
        return s.substr(begin, end-begin+1);
    }
};
