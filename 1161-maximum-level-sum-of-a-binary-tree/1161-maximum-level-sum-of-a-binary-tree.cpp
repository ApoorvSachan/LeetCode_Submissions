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
    int maxLevelSum(TreeNode* root) {
      queue<TreeNode*> q;
        q.push(root);
        int ans=-(1e9+7), res, x=0;
        while(!q.empty())
        {   x++;
            int l=q.size(), sum=0;
            while(l--)
            {
                TreeNode* t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(sum>ans)
            {
               res=x;
               ans=sum;
            }
        }
        return res;
    }
};