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
    vector<int> trav(TreeNode *r)
    {   if(r==NULL) return {};
        vector<int> l,ri;
        l=trav(r->left);
        l.push_back(r->val);
        ri=trav(r->right);
        l.insert(l.end(),ri.begin(),ri.end());
        return l;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1=trav(root1);
        vector<int> t2=trav(root2);
        t1.insert(t1.end(),t2.begin(),t2.end());
        sort(t1.begin(),t1.end());
        return t1;
    }
};