/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* fun(vector<ListNode*> &v, int l, int h)
    {
        if(l>h) return NULL;
        int m=(l+h)>>1;
        TreeNode* n=new TreeNode(v[m]->val);
        n->left=fun(v,l,m-1);
        n->right=fun(v,m+1,h);
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> v;
       while(head!=NULL)
       {
           v.push_back(head);
           head=head->next;
       }
       return fun(v,0,v.size()-1);
    }
};