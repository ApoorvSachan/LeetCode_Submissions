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
    void fun(TreeNode* l, TreeNode* r, int level){
        if(l==NULL) return;
        if(level%2!=0){
            int temp=l->val;
            l->val=r->val;
            r->val=temp;
        }
        fun(l->left,r->right,level+1);
        fun(l->right,r->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
     fun(root->left,root->right,1);
     return root;
    }
};