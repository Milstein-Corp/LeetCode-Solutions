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
    int lengthL(ListNode* head)
    {
          int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
            
          if(head==NULL)
              return head;
        if(k==0)
            return head;
          ListNode* fastptr=head;
          ListNode* slowptr=head;
        
        int lenList=lengthL(head);
        k=k%lenList;
         while(k--)
             fastptr=fastptr->next;
        // if(fastptr==NULL)
        //     return head;
        while(fastptr!=NULL && fastptr->next!=NULL )
        {
        fastptr=fastptr->next;
        slowptr=slowptr->next;
        }
        fastptr->next=head;
        head=slowptr->next;
        slowptr->next=NULL;
        return head;
    }
};