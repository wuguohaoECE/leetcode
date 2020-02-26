设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。
这里需要注意不能用int，而需要用unsigned int。因为c++里面规定了int的负数不能进行移位运算。
class Solution {
public:
    int add(int a, int b) {
        unsigned int carry = b;
        unsigned int ans = a;
        while(carry != 0){
            unsigned int temp = ans;
            ans = ans ^ carry;
            carry = (temp & carry) << 1;
        }
        return ans;
    }
};
