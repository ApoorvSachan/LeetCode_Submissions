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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      queue<TreeNode*> q;
      if(root==NULL) return ans;
      q.push(root);
      while(!q.empty())
      {
          int l=q.size();
          while(l--)
          {   
              if(q.front()->left) q.push(q.front()->left);
              if(q.front()->right) q.push(q.front()->right);
              if(l+1==1)
                  ans.push_back(q.front()->val);
              q.pop();    
          }      
      }
      return ans;
    }
};