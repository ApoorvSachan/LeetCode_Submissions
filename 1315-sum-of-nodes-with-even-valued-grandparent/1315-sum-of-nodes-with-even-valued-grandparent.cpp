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
    void fun(TreeNode* r,int &sum)
    {   if(r==NULL) return;
        if(r->val%2==0)
        {   
            if(r->left!=NULL)
                {if(r->left->left!=NULL) sum+=r->left->left->val;
                 if(r->left->right!=NULL) sum+=r->left->right->val;
                }
            if(r->right!=NULL)
                {if(r->right->left!=NULL) sum+=r->right->left->val;
                 if(r->right->right!=NULL) sum+=r->right->right->val;
                }
        }
        fun(r->left,sum);
        fun(r->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        fun(root,sum);
        return sum;
    }
};