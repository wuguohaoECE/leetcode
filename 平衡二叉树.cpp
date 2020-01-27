//6ms 508k depth作为输入
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth;
        return IsBalanced(pRoot, depth);
    }
    bool IsBalanced(TreeNode* pRoot, int& depth){
        if(pRoot == NULL){
            depth = 0;
            return true;
        }
        int left; int right;
        if(IsBalanced(pRoot->left, left) && IsBalanced(pRoot->right, right)){
            int diff = left-right;
            if(diff <= 1 && diff >= -1){
                depth = left>right ? left+1 : right+1;
                return true;
            }
            return false;
        }
        return false;
    }
};

//4ms 380k IsBalance 作为输入
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL) return true;
        bool IsBalance = true;
        int left = IsBalanced(pRoot->left, IsBalance);
        if(IsBalance) {
            int right = IsBalanced(pRoot->right, IsBalance);
            if(IsBalance && (left - right) <= 1 && (left - right) >= -1) return true;
            return false;
        }
        return false;
    }
    int IsBalanced(TreeNode* pRoot, bool& IsBalance){
        if(IsBalance){
            if(pRoot == NULL) return 0;
            int left = IsBalanced(pRoot->left, IsBalance);
            if(IsBalance) {
                int right = IsBalanced(pRoot->right, IsBalance);
                if(IsBalance){
                    if( (left - right) <= 1 && (left - right) >= -1){
                        return left > right > 0 ? left+1 : right+1;
                    }
                    IsBalance = false;
                    return 0;
                };
                return 0;
            }
        }
        return 0;
    }
};
