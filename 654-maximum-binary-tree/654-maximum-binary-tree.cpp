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
    TreeNode* fun(vector<int> n,int l,int r)
    {   if(r<l) return NULL;
        TreeNode* le,*ri;
        int m=max_element(n.begin()+l,n.begin()+r+1)-n.begin();
        le=fun(n,l,m-1);
        ri=fun(n,m+1,r);
        TreeNode *t=new TreeNode(n[m]);
        t->left=le;
        t->right=ri;
        return t;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};