class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return vector<int>();
        int i = 0; int j = array.size()-1;
        while(array[i]+array[j] != sum && i < j){
            if(array[i]+array[j] < sum) ++i;
            else --j;
        }
        if(i==j) return vector<int>();
        return vector<int>({array[i], array[j]});
    }
};
