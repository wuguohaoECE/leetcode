class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1->val == pRoot2->val)
                result = DoesTree1hasTree2(pRoot1, pRoot2);
            if(result == false)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(result == false)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }
    bool DoesTree1hasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL) return true;
        if(pRoot1 == NULL || pRoot1->val != pRoot2->val) return false;
        return DoesTree1hasTree2(pRoot1->left, pRoot2->left)&&
            DoesTree1hasTree2(pRoot1->right, pRoot2->right);
    }
};
