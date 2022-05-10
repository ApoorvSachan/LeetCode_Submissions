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
    unordered_map<TreeNode*,int> dp;
    int fun(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()) return dp[root];
        int sum=0,sum1=0;
        sum+=root->val;
        if(root->left)
        sum=sum+fun(root->left->left)+fun(root->left->right);
        if(root->right)
        sum=sum+fun(root->right->left)+fun(root->right->right);
        sum1=fun(root->left)+fun(root->right);
        return dp[root]=max(sum,sum1);
    }
    int rob(TreeNode* root) {
        return fun(root);
    }
};