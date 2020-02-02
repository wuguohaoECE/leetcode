class Solution {
public:
    long long Max;
    long Sum;
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        Sum = getSum(root);
        Max = LONG_MIN;
        Helper(root);
        return Max % (long long)(1000000000+7);
    }
    long Helper(TreeNode* root){
        long L = 0,R = 0;
        if(root->left != NULL) L = Helper(root->left);
        if(root->right != NULL) R = Helper(root->right);
        long curr = L + R + root->val;
        if(curr * (Sum - curr) > Max) Max = curr * (Sum - curr);
        return curr;
    }
    long getSum(TreeNode* root){
        if(root == NULL) return 0;
        return getSum(root->left) + getSum(root->right) + (long)root->val;
    }
};
