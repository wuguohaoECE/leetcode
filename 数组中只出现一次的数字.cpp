class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int num = 0;
        for(int i = 0; i < data.size(); ++i){
            num ^= data[i]; //异或，二进制位上相同得0，不相同得1
        }
        int FirstDigit = FindFirstDigit(num);
        *num1 = 0; *num2 = 0;
        for(int i = 0; i < data.size(); ++i){
            if(IsSameGroup(data[i], FirstDigit)){
                *num1 ^= data[i];
            }
            else{
                *num2 ^= data[i];
            }
        }
    }
    int FindFirstDigit(int num){
        int FirstDigit = 0;
        while( (num & 1) == 0 && FirstDigit < 8*sizeof(int)){ // (num & 1) 必须加括号
            num = num >> 1;
            ++FirstDigit;
        }
        return FirstDigit;
    }
    bool IsSameGroup(int num, int FirstDigit){
        num = num >> FirstDigit;
        return num & 1;
    }
    
};
