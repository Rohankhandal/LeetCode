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
ListNode* reverse(ListNode* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* forward=curr->next;
    while(curr)
    {
        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;
    }
    return prev;
    
}
    ListNode* doubleIt(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        
        head=reverse(head);
        ListNode*temp=head;
        int carry=0;
        while(temp!=NULL)
        {
            int sum=temp->val*2+carry;
            temp->val=sum%10;
            carry=sum/10;

            temp=temp->next;
        }
       
        head=reverse(head);
        while(carry)
        {
            ListNode *node=new ListNode(carry%10);
            node->next=head;
            head=node;
            
            carry=carry/10;
        }
         return head;

    }
};