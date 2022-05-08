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
    TreeNode* build(vector<int>&i, vector<int> &p, int is, int ie, int ps, int pe, unordered_map<int,int> &m)
    {
        if(is>ie || ps>pe) return NULL;
        int l=m[p[pe]];
        TreeNode* root=new TreeNode(p[pe]);
        root->right=build(i,p,l+1,ie,pe-(ie-l),pe-1,m);
        root->left=build(i,p,is,l-1,ps,pe-(ie-l)-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> m;
    for(int i=0;i<inorder.size();i++)
        m[inorder[i]]=i;
    return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,m);
    }
};