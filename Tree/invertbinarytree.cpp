 TreeNode* invertTree(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return NULL;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
                TreeNode *curr=q.front();
                q.pop();
            swap(curr->left,curr->right);
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        return root;
    }
