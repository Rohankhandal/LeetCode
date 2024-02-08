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
int getLength(ListNode* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=getLength(headA);
        int len2=getLength(headB);
        if(len1>len2)
        {
            int rem=len1-len2;
           
            while(rem--)
            {
                headA=headA->next;
            }
        }
        else
        {
            int rem=len2-len1;
            
            while(rem--)
            {
                headB=headB->next;
            }
        }
        ListNode*l1=headA;
        ListNode*l2=headB;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1==l2)
            {
                return l1;
            }
            l1=l1->next;
            l2=l2->next;
        }
        return NULL;
    }
};