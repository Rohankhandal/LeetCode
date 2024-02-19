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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*dummy=new ListNode(-101);
        dummy->next=head;
        ListNode*prev=NULL;
        ListNode*curr=dummy;
        while(curr!=NULL && curr->next)
        {
            int flag=0;
            while(curr!=NULL && curr->next&&curr->val==curr->next->val)
            {
                curr->next=curr->next->next;
                flag=1;
            }
            if(flag==1)
            {
                prev->next=curr->next;
                if(curr->next)
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
            
            
            
        }
        return dummy->next;
    }
};