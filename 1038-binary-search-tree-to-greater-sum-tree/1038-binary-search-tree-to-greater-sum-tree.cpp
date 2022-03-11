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
    void fun(TreeNode* r,int &s)
    {
        if(r==NULL) return;
        fun(r->right,s);
        s+=r->val;
        r->val=s;
        fun(r->left,s);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
        fun(root,s);
        return root;
    }
};