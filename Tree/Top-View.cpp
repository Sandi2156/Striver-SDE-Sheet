#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};
    // Write your code here.
    queue<pair<TreeNode<int> *, int>> que;
    que.push(make_pair(root, 0));
    map<int,int> mp;
    
    while(!que.empty())
    {
        for(int i = que.size()-1; i >= 0; i--)
        {
            pair<TreeNode<int> *, int> node = que.front();
            que.pop();
            if(mp.find(node.second) == mp.end())
                mp[node.second] = node.first->val;
            if(node.first->left)
                que.push({node.first->left, node.second-1});
            if(node.first->right)
                que.push({node.first->right, node.second+1});
        }
    }
    
    vector<int> res;
    for(auto it: mp) res.push_back(it.second);
    return res;
}
