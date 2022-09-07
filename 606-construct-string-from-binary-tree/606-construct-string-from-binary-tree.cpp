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
    void fun(TreeNode* root, string &s){
        if(root==NULL) return;
        if(root->left==NULL && root->right!=NULL){
            s+="("+to_string(root->val)+"()";
            fun(root->right,s);
            s+=')';
        }
        else{
            s+="("+to_string(root->val);
            fun(root->left,s);
            fun(root->right,s);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
    if(root==NULL) return "";
    string s;
    fun(root,s);
    return s.substr(1,s.size()-2);
    }
};