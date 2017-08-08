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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        else if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
            return l1;
        
        ListNode* ansList=NULL; 
        ListNode* ansListTail=NULL;
        
        while(l1 || l2)
        {
        ListNode* newnode;
            if(l1 && l2)
            {
                if(l1->val<=l2->val)
                {
                    newnode=new ListNode(l1->val);
                    l1=l1->next;
                }
                else {
                    newnode=new ListNode(l2->val);
                    l2=l2->next;
                }
            }
            else if(l1)
            {
                newnode=new ListNode(l1->val);
                l1=l1->next;
            }
            else {
                newnode=new ListNode(l2->val);
                    l2=l2->next;
            }
            
            if(ansList==NULL)
            {
             ansList=newnode;
                ansListTail=ansList;
            }
            else {
                    ansListTail->next=newnode;
                   ansListTail=ansListTail->next;
            }
        }
        return ansList;
        
    }
};