class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> Position(128, str.size());
        for(int i = 0; i < str.size(); ++i){
            if(Position[(int)str[i]] == str.size()) {
                Position[(int)str[i]] = i;
            }
            else if (Position[(int)str[i]] != str.size()+1){
                Position[(int)str[i]] = str.size()+1;
            }
        }
        int Min = Position[0];
        for(int i = 1; i < 128; ++i){
            if(Position[i] < Min) Min = Position[i];
        }
        if(Min >= str.size()) return -1;
        return Min;
    }
};
