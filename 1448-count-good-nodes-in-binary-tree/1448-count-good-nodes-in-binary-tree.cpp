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
    void fun(TreeNode* root, int mval, int &count){
        if(!root) return;
        if(root->val>=mval)
            count++;
        fun(root->left,max(mval,root->val),count);
        fun(root->right,max(mval,root->val),count);
    }
    int goodNodes(TreeNode* root) {
      int count=0;
      fun(root,INT_MIN,count);
      return count;  
    }
};