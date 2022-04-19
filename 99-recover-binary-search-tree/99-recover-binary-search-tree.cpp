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
    vector<TreeNode*> t;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && prev->val>root->val)
        {   if(t.size()==0)
            {t.push_back(prev); t.push_back(root);}
            else
            t[1]=root;
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t[0]->val,t[1]->val);
    }
};