// dp+dfs 
class Solution {
public:
    int Max = 0;
    int maxJumps(vector<int>& arr, int d) {
        if(arr.size() == 0) return 0;
        vector<int> JumpsCounts(arr.size(), -1);
        for(int i = 0; i < arr.size(); ++i){
            dfs(arr, JumpsCounts, d, i);
        }
        return Max+1;
    }
    int dfs(vector<int>& arr,vector<int>& JumpsCounts, int d, int i){
        if(JumpsCounts[i] != -1) return JumpsCounts[i];
        int L = i-d < 0 ? 0 : i-d;
        int R = i+d > arr.size() - 1 ? arr.size() - 1 : i+d;
        int ans = 0;
        for(int j = i-1; j >= L; --j){
            if(arr[j] < arr[i]){
                int jstep = dfs(arr, JumpsCounts, d, j);
                if(jstep+1 > ans) ans = jstep+1;
            }
            else{
                break;
            }
        }
        for(int j = i+1; j <= R; ++j){
            if(arr[j] < arr[i]){
                int jstep = dfs(arr, JumpsCounts, d, j);
                if(jstep+1 > ans) ans = jstep+1;
            }
            else{
                break;
            }
        }
        if(ans > Max) Max = ans;
        //cout << i << " " << ans <<endl;
        return ans;
    }
};
