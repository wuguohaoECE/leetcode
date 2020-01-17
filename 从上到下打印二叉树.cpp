class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> output;
        if(root == NULL) return output;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            output.push_back(curr->val);
            if(curr->left != NULL) queue.push(curr->left);
            if(curr->right != NULL) queue.push(curr->right);
        }
        return output;
    }
};
