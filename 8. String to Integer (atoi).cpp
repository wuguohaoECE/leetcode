class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        auto it = str.begin();
        while(it != str.end() && *it == ' '){ //去space
            ++it;
        }
        if(it == str.end()) return 0;
        char operand;
        if(*it == '+' || *it == '-'){ //识别正负号
            operand = *it;
            ++it;
        }
        else if(*it >= '0' && *it <= '9'){
            operand = '+';
        }
        else{
            return 0;
        }
        while(it != str.end() && *it >= '0' && *it <= '9'){
            if(ans*10+*it-'0' > INT_MAX && operand == '+') return INT_MAX; //识别溢出
            if(ans*10 +*it-'0' > (long)INT_MAX+1 && operand == '-' ) return INT_MIN;
            ans *= 10;
            ans += *it-'0';
            ++it;
        }
        if(operand == '-') return (int)(-ans);
        return ans;
    }
};
