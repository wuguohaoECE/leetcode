class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int num = numbers[0]; int freq = 0;
        for(int i = 0; i < numbers.size(); ++i){
            if(num == numbers[i]){
                ++freq;
            }
            else{
                if(freq > 0){
                    --freq;
                }
                else{
                    num = numbers[i];
                    ++freq;
                }
            }
        }
        if(freq > 0 && Check(numbers, num)) return num;
        return 0;
    }
    bool Check(vector<int>& numbers, int num){
        int count = 0;
        for(int i = 0; i < numbers.size(); ++i){
            if(num == numbers[i]) ++count;
        }
        if(count > numbers.size()/2) return true;
        return false;
    }
};
