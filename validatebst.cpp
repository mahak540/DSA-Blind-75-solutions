bool inorder(TreeNode *root,int &prev)
    {
        if(!root)
        return true;
        if(!inorder(root->left,prev))
        return false;
        if(prev >= root->val)
        return false;
        
        prev=root->val;
        
        return inorder(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        int prev=INT_MIN;
        return inorder(root,prev);
    }
