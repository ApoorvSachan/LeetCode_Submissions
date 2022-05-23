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
    int count=0;
    bool ispal(vector<int> &freq)
    {  int odd=0;
       for(auto i:freq)
       {
           if(i%2!=0) odd++;
           if(odd>1) return 0;
       }
     return 1;
    }
    void dfs(TreeNode* root, vector<int> freq)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            freq[root->val]++;
            if(ispal(freq)) count++;
            return;
        }
        freq[root->val]++;
        dfs(root->left,freq);
        dfs(root->right,freq);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        dfs(root,freq);
        return count;
    }
};