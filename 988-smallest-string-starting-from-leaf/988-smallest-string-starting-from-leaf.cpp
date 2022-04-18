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
    void f(TreeNode* root, string s, vector<string> &ans)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            s+=(root->val+'a');
            reverse(s.begin(),s.end());
            ans.push_back(s);
            return;
        }
        s+=(root->val+'a');
        f(root->left,s,ans);
        f(root->right,s,ans);
    }
    string smallestFromLeaf(TreeNode* root) {
       vector<string> ans;
        string s;
        f(root,s,ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};