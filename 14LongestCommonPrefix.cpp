class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return string();
        size_t size = strs[0].length();
        for(size_t i = 1; i < strs.size(); ++i){
            size = min(size, strs[i].length());
        }
        size_t MaxLength = 0;
        while(MaxLength < size){
            char ToBeCompare = strs[0][MaxLength];
            for(size_t i = 1; i < strs.size(); ++i){
                if(strs[0][MaxLength] != strs[i][MaxLength]) return strs[0].substr(0, MaxLength);
            }
            ++MaxLength;
        }
        return strs[0].substr(0, size);
    }
};
