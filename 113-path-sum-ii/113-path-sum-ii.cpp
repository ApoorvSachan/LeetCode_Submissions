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
    void f(TreeNode* root, int &t, int sum, vector<int> p, vector<vector<int>> &ans)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {   if(sum+root->val==t)
            {   p.push_back(root->val);
                ans.push_back(p);
            }
            return;
        }
        p.push_back(root->val);
        f(root->left,t,sum+root->val,p,ans);
        if(root->right!=NULL)
            f(root->right,t,sum+root->val,p,ans);
        p.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> p;
        vector<vector<int>> ans;
        if(root==NULL) return {};
        f(root,targetSum,0,p,ans);
        return ans;
    }
};