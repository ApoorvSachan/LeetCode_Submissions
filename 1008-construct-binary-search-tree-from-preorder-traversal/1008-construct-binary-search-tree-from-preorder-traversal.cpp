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
    TreeNode* fun(vector<int> pre,vector<int> in,int lp,int rp, int li, int ri)
    {   if(lp>rp || li>ri)
            return NULL;
        TreeNode *t=new TreeNode(pre[lp]);
        int m=find(in.begin()+li,in.begin()+ri+1,pre[lp])-in.begin();
        TreeNode *l,*r;
        int len=m-li;
        l=fun(pre,in,lp+1,lp+len,li,m-1);
        r=fun(pre,in,lp+len+1,rp,m+1,ri);
        t->left=l;
        t->right=r;
        return t;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        vector<int> in=p;
        sort(in.begin(),in.end());
        return fun(p,in,0,p.size()-1,0,in.size()-1);
    }
};