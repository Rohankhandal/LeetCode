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
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*forward=head;
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
        head=reverse(head);
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyNode=dummy;
        int high=INT_MIN;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(dummyNode->val==-1)
            {
                dummyNode->next=temp;
                dummyNode=temp;
                high=temp->val;
                
            }
            else if(temp->val>=high)
            {
                dummyNode->next=temp;
                dummyNode=temp;
                high=temp->val;
            }

            temp=temp->next;
        }
        dummyNode->next=NULL;
        return reverse(dummy->next);

    }
};