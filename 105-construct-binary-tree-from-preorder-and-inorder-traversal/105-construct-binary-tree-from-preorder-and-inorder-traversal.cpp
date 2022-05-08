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
    TreeNode* build(vector<int> &p,vector<int> &i,int ps, int pe, int is, int ie,unordered_map<int,int> &m)
    {
        if(ps>pe || is>ie) return NULL;
        int l=m[p[ps]];
        TreeNode* root=new TreeNode(p[ps]);
        root->left=build(p,i,ps+1,ps+l-is,is,l-1,m);
        root->right=build(p,i,l-is+ps+1,pe,l+1,ie,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
    }
};