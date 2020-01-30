//时间O(n2) 空间O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int LeftMax = 0;
        int MostWater = 0;
        for(int i = 0; i < height.size(); ++i){
            if(height[i] <= LeftMax) continue;
            else LeftMax = height[i];
            for(int j = i+1; j < height.size(); ++j){
                int currwater = (j-i) * min(height[i], height[j]);
                if(currwater> MostWater) MostWater = currwater;
            }
        }
        return MostWater;
    }
};

//双指针线性操作。时间O(n) 空间O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int MostWater = 0;
        int Left = 0, Right = height.size()-1;
        while(Left != Right){
            int currwater = (Right-Left) * min(height[Left], height[Right]);
            if(currwater > MostWater) MostWater = currwater;
            if(height[Left] < height[Right]) {
                ++Left;
            }
            else {
                --Right;
            }
        }
        return MostWater;
    }
};
