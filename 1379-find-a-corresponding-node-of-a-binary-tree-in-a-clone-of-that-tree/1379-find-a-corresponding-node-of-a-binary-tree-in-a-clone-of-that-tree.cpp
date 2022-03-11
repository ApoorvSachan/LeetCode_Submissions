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
    void path(TreeNode* o,vector<char> p,TreeNode *t,vector<vector<char>> &an)
    {   if(o==NULL) {return;}
        if(o==t) {an.push_back(p); return;}
        p.push_back('L');
        path(o->left,p,t,an);
        p.pop_back();
        p.push_back('R');
        path(o->right,p,t,an);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<char> p;
        vector<vector<char>> an;
        path(original,p,target,an);
        if(an.size()==0 && original==cloned) return cloned;
        TreeNode* temp=cloned;
        int i=0;
        while(i!=an[0].size())
        {   
            if(an[0][i]=='L') temp=temp->left;
            else if(an[0][i]=='R') temp=temp->right;
            i++;
        }
        return temp;
    }
};