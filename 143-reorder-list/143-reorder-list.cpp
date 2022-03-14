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
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* t=head;
        while(t!=NULL)
        {
            s.push(t);
            t=t->next;
        }
        t=head;
        int l=(s.size()-1)/2;
        for(int i=1;i<=l;i++)
        {   ListNode *temp=t->next;
            t->next=s.top();
            s.top()->next=temp;
            s.pop();
            t=temp;
        }
        s.top()->next=NULL;
    
    }
};