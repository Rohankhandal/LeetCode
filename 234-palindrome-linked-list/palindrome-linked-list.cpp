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
ListNode* reverse(ListNode *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode *forward=curr->next;
    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;

        prev=curr;
        curr=forward;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
        return true;
        }
        //find middle node;
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast != NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode* reverseNode=reverse(slow->next);
        ListNode*temp1=head;
        ListNode*temp2=reverseNode;
        while(temp2!=NULL)
        {
            if(temp1->val!=temp2->val)
            {
                slow->next=reverse(reverseNode);
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        reverse(reverseNode);
        return true;
    }
};