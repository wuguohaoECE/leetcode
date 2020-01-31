class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) throw exception();
        int curr = 0, ans;
        Helper(root, k, curr, ans);
        return ans;
    }
    void Helper(TreeNode* root, int k, int& curr, int& ans){
        if(curr == k) {
            return;
        }
        if(root->left != NULL) Helper(root->left, k, curr, ans);
        ++curr;
        if(curr == k) ans = root->val;
        if(root->right != NULL) Helper(root->right, k, curr, ans);
    }
};
