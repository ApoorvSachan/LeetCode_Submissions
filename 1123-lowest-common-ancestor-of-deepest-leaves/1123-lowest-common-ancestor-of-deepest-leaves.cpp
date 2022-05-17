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
    TreeNode *ans=NULL;
    int height(TreeNode *root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int fun(TreeNode *root, int h, int &mh)
    {
        if(root==NULL) return 0;
        int l=fun(root->left,h+1,mh);
        int r=fun(root->right,h+1,mh);
        if(l==r && l+h+1==mh) ans=root;
        return 1+max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root){
      int mh=height(root);
      int x=fun(root,0,mh);
        return ans;
    }
};