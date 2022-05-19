/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int l=q.size();
            vector<int> v;
            while(l--)
            {
                Node* t=q.front();
                q.pop();
                v.push_back(t->val);
                int n=t->children.size();
                for(int i=0;i<n;i++)
                    q.push(t->children[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};