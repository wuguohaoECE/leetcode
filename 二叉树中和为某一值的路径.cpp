class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> output;
        if(root == NULL) return output;
        vector<int> path;
        int currsum = 0;
        FindPath(root, currsum, expectNumber, path, output);
        return output;
    }
    void FindPath(TreeNode* root, int currsum, int targetsum, vector<int>& path, vector<vector<int>>& output){
        path.push_back(root->val);
        currsum += root->val;
        if(currsum == targetsum &&
          root->left == NULL &&
          root->right == NULL) output.push_back(path);
        if(root->left != NULL) FindPath(root->left, currsum, targetsum, path, output);
        if(root->right != NULL) FindPath(root->right, currsum, targetsum, path, output);
        currsum -= root->val;
        path.pop_back();
    }
};
