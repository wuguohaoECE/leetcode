class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return NULL;
        TreeNode* Last = NULL;
        ConvertNode(pRootOfTree, &Last);
        while(Last->left != NULL) Last = Last->left;
        return Last;
    }
    void ConvertNode(TreeNode* pNode, TreeNode** Last){
        if(pNode->left != NULL) ConvertNode(pNode->left, Last);
        pNode->left = *Last;
        if(*Last != NULL) (*Last)->right = pNode;
        *Last = pNode;
        if(pNode->right != NULL) ConvertNode(pNode->right, Last);
    }
};
