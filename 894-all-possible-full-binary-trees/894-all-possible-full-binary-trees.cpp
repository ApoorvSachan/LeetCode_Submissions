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
    unordered_map<int,vector<TreeNode*>> m;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        if(m.find(n)!=m.end()) return m[n];
        if(n==1)
        {   TreeNode *r=new TreeNode(0);
            m[1].push_back(r);
            return m[1];
        }
        for(int i=1;i<n;i++)
        {   vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> ri=allPossibleFBT(n-i-1);
            for(auto j:left)
            {for(auto k:ri)
                {TreeNode *r=new TreeNode(0);
                 r->left=j;
                 r->right=k;
                 m[n].push_back(r);
                }
            }
        }
    return m[n];
    }
};
