class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(size == 0) return false;
        return helper(&sequence[0], &sequence[size-1]);
    }
    bool helper(int* start, int* end){
        if(end == start || start+1 == end) return true;
        if(end - start == 2){
            if(start[0] < *end && start[1] > *end) return true;
        }
        int* pfind = start;
        while(pfind != end){
            if(*pfind > *end) break;
            ++pfind;
        }
        int* testright = pfind;
        while(testright != end){
            if(*testright < *end) return false;
            ++testright;
        }
        if(pfind == start || pfind == end) return helper(start, --end);
        return helper(start, pfind-1)&&helper(pfind, --end);
    }
};
