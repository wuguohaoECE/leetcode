class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size()) return false;
        auto poppoi = popV.begin();
        stack<int> stack;
        for(auto pushpoi = pushV.begin(); pushpoi != pushV.end(); ++pushpoi){
            if(*pushpoi == *poppoi){
                ++poppoi;
                continue;
            }
            stack.push(*pushpoi);
        }
        while(!stack.empty() && stack.top() == *poppoi){
            stack.pop();
            ++poppoi;
        }
        if(stack.empty()) return true;
        return false;
    }
};
