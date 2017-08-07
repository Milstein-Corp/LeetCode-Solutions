/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head,ListNode* prev=NULL) {
        
        if(head==NULL)
        {
          return head;
        }
       
        if(head->next==NULL)
        {
          head->next=prev;
            return head;
        }
        
        ListNode* temp=head->next;
        head->next=prev;
      return  reverseList(temp,head);
    }
};