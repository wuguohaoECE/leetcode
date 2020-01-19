class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0) return 0;
        if(index == 1) return 1;
        vector<int> uglyvec({1});
        int ugly2 = 0; int ugly3  = 0; int ugly5 = 0;
        while(uglyvec.size() != index){
            while(uglyvec[ugly2]*2 <= uglyvec.back()) ++ugly2;
            while(uglyvec[ugly3]*3 <= uglyvec.back()) ++ugly3;
            while(uglyvec[ugly5]*5 <= uglyvec.back()) ++ugly5;
            uglyvec.push_back(MinInThree(uglyvec[ugly2]*2, uglyvec[ugly3]*3, uglyvec[ugly5]*5));
        }
        return uglyvec.back();
    }
    int MinInThree(int a, int b, int c){
        int Min = min(a,b);
        return min(Min, c);
    }
};
