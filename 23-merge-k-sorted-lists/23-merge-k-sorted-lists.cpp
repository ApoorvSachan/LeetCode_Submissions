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
struct cmp
{
    bool operator()(const ListNode* a, const ListNode* b) const
    {
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<ListNode*,vector<ListNode*>, cmp> q;
        for(auto i: lists)
        {   if(i!=NULL)
            q.push(i);
        }
        ListNode *head=new ListNode();
        ListNode *curr=head;
        while(!q.empty())
        {
            ListNode* t=q.top();
            q.pop();
            curr->next=t;
            curr=t;
            if(t->next!=NULL)
                q.push(t->next);
        }
        return head->next;
    }
};