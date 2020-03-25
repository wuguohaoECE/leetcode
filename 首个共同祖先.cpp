class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* Left = lowestCommonAncestor(root->left, p, q);
        TreeNode* Right = lowestCommonAncestor(root->right, p ,q);
        if(Left != NULL && Right != NULL){
            return root;
        }
        if(Left != NULL){
            return Left;
        }
        if(Right != NULL){
            return Right;
        }
        return NULL;
    }
};
