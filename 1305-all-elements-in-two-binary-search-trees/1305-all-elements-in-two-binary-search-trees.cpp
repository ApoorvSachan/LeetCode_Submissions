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
    void trav(TreeNode *r,vector<int> &ans)
    {   if(r==NULL) return;
        trav(r->left,ans);
        ans.push_back(r->val);
        trav(r->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        trav(root1,ans);
        trav(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};