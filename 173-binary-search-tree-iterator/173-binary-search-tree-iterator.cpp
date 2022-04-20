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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        leftsubtree(root);
    }
    
    int next() {
        TreeNode* t=s.top();
        s.pop();
        if(t->right)
            leftsubtree(t->right);
        return t->val;
    }
    
    bool hasNext() {
        if(!s.empty())
            return 1;
        return 0;
    }
    void leftsubtree(TreeNode *r)
    {
        while(r!=NULL)
        {
            s.push(r);
            r=r->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */