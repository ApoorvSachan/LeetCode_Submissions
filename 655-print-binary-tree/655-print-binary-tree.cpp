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
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    vector<vector<string>> printTree(TreeNode* root) {
       int level=0;
       int h=height(root);
       int w=(1<<h)-1;
       vector<vector<string>> v(h, vector<string> (w,""));
       queue<pair<TreeNode*,vector<int>>> q;
        q.push({root,{w/2,0,w-1}});
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                pair<TreeNode*,vector<int>> t=q.front();
                q.pop();
                TreeNode* node=t.first; vector<int> p=t.second;
                v[level][p[0]]=to_string(node->val);
                if(node->left) q.push({node->left,{(p[0]-p[1])/2+p[1],p[1],p[0]-1}});
                if(node->right) q.push({node->right,{((p[2]-p[0])/2)+1+p[0],p[0]+1,p[2]}});
            }
            level++;
        }
        return v;
    }
};