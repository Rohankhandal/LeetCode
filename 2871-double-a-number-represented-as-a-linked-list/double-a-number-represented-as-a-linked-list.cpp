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
        
        ListNode*temp=reverse(head);
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*tail=dummy;
        int sum=0,digit=0;
        while(temp)
        {
            sum=temp->val*2+carry;
            digit=sum%10;
            carry=sum/10;

            //insert new node in head of ans;
            ListNode*newNode=new ListNode(digit);
            newNode->next=tail->next;
            tail->next=newNode;

            temp=temp->next;
        }
        if(carry)
        {
            ListNode*newNode=new ListNode(carry);
            newNode->next=tail->next;
            tail->next=newNode;
        }

        return dummy->next;
    }
};