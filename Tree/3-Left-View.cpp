vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root == NULL) return {};
    vector<int> result;
    queue<TreeNode<int>*> que;
    que.push(root);
    
    while(!que.empty())
    {
        result.push_back(que.front()->data);
        for(int i = que.size()-1; i >= 0; i--)
        {
            TreeNode<int>* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        
    }
    return result;
    
}
