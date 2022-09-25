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
    bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int l=q.size(), temp=q.size();
        int prev=0;
        while(l--){
        if(level%2==0 && (q.front()->val%2==0 || (l!=temp-1 && q.front()->val<=prev))) return 0;
        if(level%2!=0 && (q.front()->val%2!=0 || (l!=temp-1 && q.front()->val>=prev))) return 0;
        auto f=q.front();
        q.pop();
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
        prev=f->val;
        }
        level++;
    }
    return 1;
    }
};