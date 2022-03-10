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
    int height(TreeNode* r)
    {   if(r==NULL) return 0;
        return 1+max(height(r->left),height(r->right));
    }
    int f(TreeNode* root,int sum,int h)
    {   if(root!=NULL && h==1) {sum+=root->val; return sum;}
        if(root==NULL && h!=0) return sum;
        int l=f(root->left,sum,h-1);
        int r=f(root->right,sum,h-1);
        return l+r;
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root);
        return f(root,0,h);
    }
};