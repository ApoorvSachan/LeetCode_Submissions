/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode * root, TreeNode* par, unordered_map<TreeNode*,TreeNode*> &m){
        if(root==NULL) return;
        m[root]=par;
        parent(root->left,root,m);
        parent(root->right,root,m);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*> m;
    parent(root,NULL,m);
    queue<pair<TreeNode*,int>> q;
    q.push({target,0});
    unordered_set<int> vis;
    while(!q.empty()){
        int l=q.size();
        if(q.front().second==k) break;
        while(l--){
            auto t=q.front();
            vis.insert(t.first->val);
            q.pop();
            if(t.first->left && vis.find(t.first->left->val)==vis.end())
                q.push({t.first->left,t.second+1});
            if(t.first->right && vis.find(t.first->right->val)==vis.end())
                q.push({t.first->right,t.second+1});
            if(m[t.first] && vis.find(m[t.first]->val)==vis.end())
                q.push({m[t.first],t.second+1});
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front().first->val);
        q.pop();
    }
    return ans;
    }
};