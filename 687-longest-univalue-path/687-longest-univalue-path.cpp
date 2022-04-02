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
    int ans=INT_MIN;
    int f(TreeNode* root) {
        if(root==NULL)
            return 0;
        int l=0, r=0;
        int left=f(root->left);
        int right=f(root->right);
        if(root->left && root->left->val==root->val)
            l=left+1;
        if(root->right && root->right->val==root->val)
            r=right+1;
        ans=max(ans,l+r);
        return max(l,r);
    }
    int longestUnivaluePath(TreeNode* root) {
        int a=f(root);
        if(root==NULL) return 0;
        return ans;
    }
};