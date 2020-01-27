class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) return false;
        sort(numbers.begin(), numbers.end());
        auto it = numbers.begin();
        int NumOfZero = 0;
        while(*it == 0){
            ++it;
            ++NumOfZero;
        }
        int curr = *it;
        ++it;
        while(it != numbers.end()){
            if(*it == curr) return false;
            NumOfZero -= *it-curr-1;
            if(NumOfZero < 0) return false;
            curr = *it;
            ++it;
        }
        return true;
    }
};
