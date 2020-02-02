class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.length() != end.length()) return false;
        int i = 0, j = 0, size = start.length();
        while(i < size && j < size){
            cout << "7" << endl;
            while(i < size && start[i] == 'X'){
                ++i;
            }
            while(j < size && end[j] == 'X'){
                ++j;
            }
            cout << i << " " << j << endl;
            if(i == size && j == size) return true;
            if(i == size || j == size) return false;
            if(start[i] != end[j]) return false;
            if(start[i] == 'L' && i < j) return false;
            if(start[i] == 'R' && i > j) return false;
            ++i; ++j;
        }
        return true;
    }
};
