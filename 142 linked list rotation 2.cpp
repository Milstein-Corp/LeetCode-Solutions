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
    ListNode *detectCycle(ListNode *head) {
        
           if(head==NULL || head->next==NULL)
           return NULL;
           
         
           
           ListNode* slowptr=head;
           ListNode* fastptr=head;
           bool iscycle=false;
           
           while(fastptr!=NULL && fastptr->next!=NULL)
           {
               fastptr=fastptr->next->next;
               slowptr=slowptr->next;
               if(slowptr==fastptr)
               {
                   iscycle=true;
                   break;
               }
           }
           
           if(!iscycle)
           {
               return NULL;
           }
           
           slowptr=head;
           
           while(slowptr!=fastptr)
           {
               slowptr=slowptr->next;
               fastptr=fastptr->next;
           }
           
           return slowptr;
           
           
    }
};