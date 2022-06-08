vector<int> preorderTraversal(TreeNode* root) {
        // Morris
        
        TreeNode *curr = root;
        vector<int> preorder;
        
        while(curr != NULL)
        {
            
            
            TreeNode* lc = curr->left;
            if(lc == NULL) {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                while(lc->right != NULL && lc->right != curr) lc = lc->right;
                if(lc->right == NULL) {
                    preorder.push_back(curr->val);
                    lc->right = curr;
                    curr = curr->left;
                }
                else if(lc->right == curr) {
                    lc->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        return preorder; 
    }
