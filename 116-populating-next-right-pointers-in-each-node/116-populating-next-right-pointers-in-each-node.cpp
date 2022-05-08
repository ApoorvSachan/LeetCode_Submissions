/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root==NULL) return NULL;
        q.push(root);
        while(!q.empty())
        {
            int l=q.size();
            while(l--)
            {
                Node* f=q.front();
                q.pop();
                if(l+1>1)
                {
                    f->next=q.front();
                    cout<<q.front()->val;
                }
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return root;
    }
};