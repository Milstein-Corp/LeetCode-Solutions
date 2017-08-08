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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        ListNode* ans=NULL;
        ListNode* nextans=NULL;
        
        int sum=0;
        int carry=0;
        
        while(l1 || l2 || carry)
        {
            if(l1 && l2)
            {
                sum=l1->val + l2->val;
            l1=l1->next;
                l2=l2->next;
            }
            else if(l1)
               { sum=l1->val;
                l1=l1->next;
               }
            else if(l2)
               { sum = l2->val;
                  l2=l2->next;
               }
            
            sum=sum+carry;
            carry=sum/10;
            sum=sum%10;
            
            ListNode* newnode=new ListNode(sum);
            
            if(ans==NULL)
            {
               ans=newnode;
                nextans=ans;
             }
            else {
                nextans->next=newnode;
                nextans=nextans->next;
            }
            sum=0;
            
        }
        return ans;
    }
};