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
    static bool cmp(pair<pair<int,int>,TreeNode*> a, pair<pair<int,int>,TreeNode*> b){
        if(a.first.first==b.first.first){ 
            if(a.first.second==b.first.second) return a.second->val<b.second->val; 
            return a.first.second<b.first.second;}
        return a.first.first<b.first.first;
    }
    void fun(TreeNode *root, int i, int d, vector<pair<pair<int,int>,TreeNode*>> &s){
        if(root==NULL) return;
        s.push_back({{i,d},root});
        fun(root->left,i-1,d+1,s);
        fun(root->right,i+1,d+1,s);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     vector<pair<pair<int,int>,TreeNode*>> s;
     vector<vector<int>> ans;
     fun(root,0,0,s);
     sort(s.begin(),s.end(),cmp);
     vector<int> v;
     int idx=INT_MIN;
     for(auto i=0; i<s.size(); i++){
        auto c=s[i];
        if(c.first.first==idx) v.push_back(c.second->val);
        else
        {
            if(v.size()!=0) ans.push_back(v);
            v.resize(0);
            v.push_back(c.second->val);
            idx=c.first.first;
        }
     }
     if(v.size()!=0) ans.push_back(v);
     return ans;
    }
};