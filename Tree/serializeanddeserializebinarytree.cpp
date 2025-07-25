void traverse(TreeNode* node, string& res) {
        if (!node) {
            res.append("N,");
            return;
        }

        res.append(to_string(node->val) + ",");
        traverse(node->left, res);
        traverse(node->right, res);
    }
    string serialize(TreeNode* root) {
         string res;
        traverse(root, res);
        if (!res.empty()) res.pop_back(); // Remove trailing comma
        return res;
    }
TreeNode* makeTree(queue<string>& values) {
        string snum = values.front();
        values.pop();
        if (snum == "N") return nullptr;

        TreeNode* root = new TreeNode(stoi(snum));
        root->left = makeTree(values);
        root->right = makeTree(values);
        return root;
    }
    TreeNode* deserialize(string data) {
         queue<string> values;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            values.push(token);
        }

        return makeTree(values);
    }
