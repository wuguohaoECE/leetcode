class NumArray {
    private:
    vector<int> cusum;
public:
    NumArray(vector<int>& nums): cusum(vector<int>(nums.size()+1, 0)){
        if(nums.size() != 0){
            for(int i = 0; i < nums.size(); ++i){
                cusum[i+1] = cusum[i] + nums[i];
            }
        }
    }
    
    int sumRange(int i, int j) {
        return cusum[j+1] - cusum[i];
    }
};
