#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {} ;
    
    stack<pair<BinaryTreeNode<int> *, int>> stk; // node and traverse time
    
    vector<int> inorder, preorder, postorder;
    stk.push({root, 1});
    
    while(!stk.empty())
    {
        pair<BinaryTreeNode<int> *, int> node = stk.top();
        stk.pop();
        if(node.second == 1)
        {
            preorder.push_back(node.first->data);
            node.second++;
            stk.push(node);
            if(node.first->left) {
                stk.push({node.first->left, 1});
            }
        } else if(node.second == 2) 
        {
            inorder.push_back(node.first->data);
            node.second++;
            stk.push(node);
            if(node.first->right) {
                stk.push({node.first->right, 1});
            }
        } else if(node.second == 3)
        {
            postorder.push_back(node.first->data);
        }
    }
    vector<vector<int>> res;
    res.push_back(inorder);
    res.push_back(preorder);
    res.push_back(postorder);
    
    return res;
    
}
