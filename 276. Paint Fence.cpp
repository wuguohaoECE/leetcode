class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0) return 0;
        if(n == 1) return k;
        int pprep = k, prep = k*k;//前两个和前一个的种数
        for(int i = 2; i < n; ++i){
            //与前一个相同，说明前一个与前前一个不同，即F(n-2)*(k-1)
            int SameWithPrep = pprep*(k-1);
            //与前一个不同，即F(n-1)*(k-1)
            int DiffWithPrep = prep*(k-1);
            pprep = prep;
            prep = SameWithPrep+DiffWithPrep;
        }
        return prep;
    }
};
