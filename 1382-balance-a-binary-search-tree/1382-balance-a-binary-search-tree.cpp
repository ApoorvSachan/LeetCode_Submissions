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
    void inorder(TreeNode* r,vector<int> &p)
    {   if(r==NULL) return;
        inorder(r->left,p);
        p.push_back(r->val);
        inorder(r->right,p);
    }
    TreeNode* fun(vector<int> p,int l,int r)
    {   if(l>r) return NULL;
        int m=l+(r-l)/2;
        TreeNode *t=new TreeNode(p[m]);
        TreeNode *le, *ri;
        le=fun(p,l,m-1);
        ri=fun(p,m+1,r);
        t->left=le;
        t->right=ri;
        return t;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> p;
        inorder(root,p);
        return fun(p,0,p.size()-1);
    }
};