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
    void dfs(TreeNode* root, int h, vector<pair<int,int>> &a)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            a.push_back({h,root->val});
        dfs(root->left,h+1,a);
        dfs(root->right,h+1,a);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<pair<int,int>> a;
        dfs(root,0,a);
        int ans=INT_MIN,p=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            if(a[i].first>=ans)
            {
                ans=a[i].first;
                p=i;
            }
        }
     //   for(auto i:a) cout<<i.first<<" "<<i.second<<endl;
        return a[p].second;
    }
};