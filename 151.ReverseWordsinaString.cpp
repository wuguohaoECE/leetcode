class Solution {
public:
    string reverseWords(string s) {
        reverse(s, 0, s.length()-1);
        int head = 0;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' ') continue;
            while(i != s.length() && s[i] != ' '){
                ++i;
            }
            reverse(s, head, i-1);
            head = i;
            while(s[head-1] == ' '){
                --head;
            }
            ++head;
        }
        int end = s.length()-1;
        while(end > 0 && s[end] == ' '){
            --end;
        }
        if(s[end] != ' ') return s.substr(0, end+1);
        return string();
    }

    void reverse(string& s, int begin, int end){
        while(begin < end){
            swap(s[begin], s[end]);
            ++begin; --end;
        }
    }
};
