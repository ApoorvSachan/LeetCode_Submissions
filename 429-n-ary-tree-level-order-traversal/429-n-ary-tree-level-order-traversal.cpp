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
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    while(!q.empty()){
        int l=q.size();
        vector<int> v;
        while(l--){
            auto t=q.front();
            q.pop();
            v.push_back(t->val);
            for(auto i:t->children){
                q.push(i);
            }
        }
        ans.push_back(v);
    }
    return ans;
    }
};