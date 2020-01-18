class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> out;
        if(str.empty()) return out;
        Permutation(str, out, 0);
        return out;
    }
    
    void Permutation(string& str,vector<string>&out, int begin){
        if(begin == str.size()) {
            out.push_back(str);
        }
        else{
            set<char> set;
            for(int ptr = begin; ptr < str.size(); ++ptr){
                if(!set.count(str[ptr])){
                    set.insert(str[ptr]);
                    swap(str[begin], str[ptr]);
                    Permutation(str, out, 1+begin);
                    swap(str[begin], str[ptr]);
                }
            }
        }
    }
};
