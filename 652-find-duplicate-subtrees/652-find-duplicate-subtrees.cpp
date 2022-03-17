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
    string fun(TreeNode* r, unordered_map<string,int> &m, vector<TreeNode*> &a)
    {
        if(r==NULL) return "";
        string s=to_string(r->val);
        s=s+","+fun(r->left,m,a)+","+fun(r->right,m,a);
        if(m[s]==1)
            a.push_back(r);
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      unordered_map<string,int> m;  
        vector<TreeNode*> a;
        string s=fun(root,m,a);
        return a;
    }
};