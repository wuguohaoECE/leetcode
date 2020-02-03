//暴力解法 O(n2) 
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        for(int i = 0; i < size-2; ++i){
            cout << "test" << endl;
            if(height[i+1] > height[i]){
                continue;
            }
            //此时 i+1 比 i 矮
            int Max_height = height[i+1], Max_index = i+1, j = i+2;
            for(; j < size; ++j){
                if(height[j] >= Max_height){
                    Max_height = height[j];
                    Max_index = j;
                    if(Max_height > height[i]) break;
                }
            }
            if(Max_index == i+1) continue; //一直往右都没有比第二根高，第一根不能作为边。
            int Min_height = min(height[i], Max_height);
            for(int q = i+1; q < Max_index; ++q){
                ans += Min_height - height[q];
            }
            i = Max_index - 1;
        }
        return ans;
    }
};

//因为其实每个index的存水量等于其左边最高的高度和右边最高的高度的较小值减去其本身。因此可以用两个vector记录每个index对应左边最高值和右边最高值。
//时间O(3n) 空间O(2n)
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 3) return 0;
        int ans = 0;
        vector<int> Left_Max(size, 0), Right_Max(size, 0);
        Left_Max[0] = height[0];
        for(int i = 1; i < size; ++i){
            Left_Max[i] = max(height[i], Left_Max[i-1]);
        }
        Right_Max[size-1] = height[size-1];
        for(int i = size-2; i >= 0; --i){
            Right_Max[i] = max(height[i], Right_Max[i+1]);
        }
        for(int i = 0; i < size; ++i){
            ans += min(Left_Max[i], Right_Max[i]) - height[i];
        }
        return ans;
    }
};
//双指针法，时间O(n), 空间O(1)
//对于index为i的柱子，只要其left_max比其右边任意一根柱子矮，那么i这跟柱子的存水量由left_max决定。
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size < 3) return 0;
        int ans = 0;
        int L = 0, Left_Max = height[0], R = size-1, Right_Max = height[size-1];
        while(L < R){
            if(height[L] < height[R]){
                if(height[L] > Left_Max){
                    Left_Max = height[L];
                }
                else{
                    ans += Left_Max - height[L]; //Right_Max一定是大于Left_Max的，因为如果小于的话，也就是R遍历过程中没有一个比Left_Max高，那么L就不会动了。
                }
                ++L;
            }
            else{
                if(height[R] > Right_Max){
                    Right_Max = height[R];
                }
                else{
                    ans += Right_Max -height[R];
                }
                --R;
            }
        }
        return ans;
    }
};
