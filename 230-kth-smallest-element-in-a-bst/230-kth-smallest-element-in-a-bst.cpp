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
    void inorder(TreeNode* root, int &k, int &i, int &a)
    {
        if(root==NULL) return;
        inorder(root->left,k,i,a);
        i++;
        if(i==k) {
            
            a=root->val;
            return;
        }
        inorder(root->right,k,i,a);
    }
        
    int kthSmallest(TreeNode* root, int k) {
        int a,i=0;
        inorder(root,k,i,a);
        return a;
    }
};