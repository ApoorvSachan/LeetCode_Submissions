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
    long long ans=0, mod=1e9+7;
    long long tsum(TreeNode *root){
        if(root==NULL) return 0;
        return tsum(root->left)+tsum(root->right)+root->val;
    }
    long long fun(TreeNode *root, long long &sum){
        if(root==NULL) return 0;
        int l=fun(root->left,sum);
        int r=fun(root->right,sum);
        ans=max(ans,max(l*(sum-l),r*(sum-r)));
        return l+r+root->val;
    }
    int maxProduct(TreeNode* root) {
    long long sum=tsum(root);
    long long s=fun(root,sum);
    return ans%mod;
    }
};