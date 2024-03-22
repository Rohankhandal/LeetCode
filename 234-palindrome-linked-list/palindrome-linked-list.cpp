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
        if(head==NULL|| head->next==NULL)
        {
        return head;
        }
        ListNode* prev=NULL;
        ListNode*curr=head;
        ListNode*forward=curr->next;
        while(curr)
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
        //find middle node
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*temp2=reverse(slow->next);
        ListNode*temp1=head;
        while(temp2!=NULL)
        {
            if(temp2->val != temp1->val)
                return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;


    }
};