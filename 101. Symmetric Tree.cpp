class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* L, TreeNode* R){
        if(L == NULL && R == NULL) return true;
        if(L == NULL || R == NULL) return false;
        if(L->val != R->val) return false;
        return isSymmetric(L->right, R->left) && isSymmetric(L->left, R->right);
    }
};
