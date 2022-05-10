/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        TreeNode* t=root;
        while(t!=NULL)
        {
           if((p->val<t->val && q->val>t->val) || (p->val>t->val && q->val<t->val))
               return t;
           else if(p->val==t->val) return p;
           else if(q->val==t->val) return q;
           else if(p->val>t->val && q->val>t->val)
              t=t->right;
           else
              t=t->left;
        }
      return NULL;  
    }
};