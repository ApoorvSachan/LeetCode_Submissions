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
    bool isPalindrome(ListNode* head) {
     if(head==NULL) return 1;
     ListNode *slow=head, *fast=head, *prev=NULL, *temp;
     while(fast && fast->next){
       temp=slow;
       slow=slow->next;
       fast=fast->next->next;
       temp->next=prev;
       prev=temp;
     }
     if(fast!=NULL) slow=slow->next;
     while(slow!=NULL){
         if(slow->val!=temp->val) return 0;
         slow=slow->next;
         temp=temp->next;
     }
     return 1;
    }
};