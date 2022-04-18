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
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        f(root->left,s,ans);
        f(root->right,s,ans);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        string s;
        f(root,s,ans);
        int res=0;
        for(int i=0;i<ans.size();i++)
        {
            res+=stoi(ans[i]);
          //  cout<<ans[i]<<endl;
        }
        return res;
    }
};