
int kth(TreeNode *root,int &c,int k)
    {
        if(root==NULL)
        return -1;
        int l=kth(root->left,c,k);
        if(l!=-1)
        return l;
        c++;
        if(c==k)
        return root->val;
        int r=kth(root->right,c,k);
        return r;
        
    }
    int kthSmallest(TreeNode* root, int k) {
         // add code here.
        int c=0;
        return kth(root,c,k);
    }
