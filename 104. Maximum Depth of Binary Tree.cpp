class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return max(L,R)+1;
    }
};
