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
    int count=0;
    void helper(TreeNode* root,long long int sum, int t)
    {
        if(root==NULL) return;
        sum+=root->val;
        if(sum==t)
        {
            count++;
        }
        helper(root->left,sum,t);
        helper(root->right,sum,t);
    }
    void bfs(TreeNode* root,int &t)
    {
        if(root==NULL) return;
        helper(root,0,t);
        bfs(root->left,t);
        bfs(root->right,t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        bfs(root,targetSum);
        return count;
    }
};