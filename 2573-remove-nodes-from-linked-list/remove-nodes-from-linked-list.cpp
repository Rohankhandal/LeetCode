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
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=head->next;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;

            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        head=reverse(head);
        int max=head->val;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->next->val<max)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
                 max=temp->val;
            } 
        }
        return head=reverse(head);

    }

};