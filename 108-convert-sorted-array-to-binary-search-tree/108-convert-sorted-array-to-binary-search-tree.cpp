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
    TreeNode* fun(vector<int> &n, int l, int r){
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* t=new TreeNode(n[mid]);
        t->left=fun(n,l,mid-1);
        t->right=fun(n,mid+1,r);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};