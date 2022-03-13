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
class FindElements {
public:
    TreeNode* r;
    FindElements(TreeNode* root,int x=0) {
        if(root==NULL) return;
        root->val=x;
        if(root->left!=NULL)
            FindElements(root->left,2*x+1);
        if(root->right!=NULL)
            FindElements(root->right,2*x+2);
        r=root;
    }
    bool f(TreeNode* root, int t)
    {if(root==NULL) return 0;
     if(t==root->val) return 1;
     if(f(root->left,t) || f(root->right,t))
         return 1;
     return 0;
    }
    bool find(int target) {
        return f(r,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */