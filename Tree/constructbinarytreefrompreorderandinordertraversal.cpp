TreeNode *build(unordered_map<int,int>&mp,vector<int>&preorder,int &preindex,int left,int right)
  {
      if(left>right)
      return NULL;
      int rootval=preorder[preindex];
      preindex++;
      TreeNode *root=new TreeNode(rootval);
      int i=mp[rootval];
      root->left=build(mp,preorder,preindex,left,i-1);
      root->right=build(mp,preorder,preindex,i+1,right);
      
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         unordered_map<int,int>mp;
        for(int i=0;i<preorder.size();i++)
        mp[inorder[i]]=i;
        int preindex=0;
        TreeNode *root=build(mp,preorder,preindex,0,inorder.size()-1);
        
        return root;
    }
