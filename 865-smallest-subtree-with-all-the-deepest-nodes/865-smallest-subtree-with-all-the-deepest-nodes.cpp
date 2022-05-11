/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode*q, TreeNode*r)
    {
        if(root==NULL) return NULL;
        if(root==q || root==r) return root;
        TreeNode* l=lca(root->left,q,r);
        TreeNode* rt=lca(root->right,q,r);
        if(l==NULL && rt!=NULL) return rt;
        if(l!=NULL && rt==NULL) return l;
        if(l==NULL && rt==NULL) return NULL;
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> d;
        while(!q.empty())
        {  d={};
           int l=q.size();
           while(l--)
           {
               TreeNode* t=q.front();
               q.pop();
               d.push_back(t);
               if(t->left) q.push(t->left);
               if(t->right) q.push(t->right);
           }
        }
        if(d.size()==1) return d[0];
        return lca(root,d[0],d[d.size()-1]);
    }
};